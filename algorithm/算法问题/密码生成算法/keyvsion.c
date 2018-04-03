// No.10.22 暗茫雪羽
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <signal.h>

/*
* 8到15位密钥生成：
*
* 程序设计思想：
*           1. 使用缓冲区增加生产密钥的速度， 尽量减少“IO”速度造成的瓶颈问题
*           2. 使用生产者消费者模型, 一个生产者跟单消费问题
*                   --- 由于产生密钥算法问题： 导致多个生产者生产密钥同步困难
*           3.设置两个缓冲区组成的环形缓冲区交替输出， 单个缓冲区大小暂定 4M
*           4. 在缓冲区满时， 只做一次缓冲输出
*/

#define KEY_COUNT     47
#define BUFF_SIZE     8192
#define MAX_KEY_LEN   4
#define MIN_KEY_LEN   4

typedef struct KEY_STRUCT{
  int                 str_cur_bit;                     // 当前的密钥位数
  char                str_key[MAX_KEY_LEN];            // 生成密钥
  int8_t              str_key_index[MAX_KEY_LEN];      // 每一位密钥的当前索引
}KEY, *PKEY;

typedef struct HANDLE_CELL{
  char              cell_key_array[BUFF_SIZE];       // 存放密钥的空间
  int               cell_flags;                      // 有效标志： 0 表示已经未满 | 1 表示缓冲区满
  int               cell_len;                        // 写入缓冲区的长度
  pthread_mutex_t   cell_mutex;                      // 互斥量
}CELL, *PCELL;

pthread_cond_t    cond = PTHREAD_COND_INITIALIZER;   // 条件变量
int               producer_flags = 1;                // 生产者标志
int               customer_flags = 1;                // 消费者标志    -- 0 表示等待 1 表示正在使用
int               res = 0;

const char key_word[KEY_COUNT] = {'a','b','c','d','e','f','g',
                        'h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u',
                        'v','w','x','y','z','!','@',
                        '#','$','%','^','&','*','.','-','_','1',
                        '2','3','4','5','6','7','8','9','0'};

struct timespec time_start;     // 记录开始时间
struct timespec time_end;       // 记录结束时间

void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}

void err_sys(const char *msg)
{
  printf("%s:%s\n", msg, strerror(errno));
  exit(errno);
}

void * pthread_producer_key(void * args);  // 生产者线程
void * pthread_customer_key(void * args);  // 消费者线程

int key_modify(PKEY key);

int main(int argc, char const *argv[])
{
  pthread_t         th_product;       // 生产者线程
  pthread_t         th_custom;        // 消费者线程
  pthread_attr_t    th_attr;
  CELL              cell[2];          // 生产消费空间

  // 初始化缓冲区
  int i;
  for(i = 0; i < 2; i++)
  {
      memset(cell[i].cell_key_array, 0, sizeof(cell[i].cell_key_array));
      cell[i].cell_flags  = 0;
      cell[i].cell_len    = 0;
      pthread_mutex_init(&cell[i].cell_mutex, NULL);
  }

  /*
  if(pthread_attr_init(&th_attr) == -1)
    err_sys("pthread_attr_init error");
  if(pthread_attr_setdetachstate(&th_attr, PTHREAD_CREATE_DETACHED) == -1)
    err_sys("pthread_attr_setdetachstate error");
  */
  if(pthread_create(&th_product, NULL, pthread_producer_key, (void *)cell) == -1)
    err_sys("pthread_create error");

  if(pthread_create(&th_custom, NULL, pthread_customer_key, (void *)cell) == -1)
    err_sys("pthread_create error");

  if(pthread_attr_destroy(&th_attr) == -1)
    err_sys("pthread_attr_destroy error");

  pthread_join(th_product, NULL);
  pthread_join(th_custom, NULL);

  return 0;
}

// 生产者线程
void * pthread_producer_key(void * args)
{
    int               i;
    int               index;            // 缓冲区索引
    char              *buffer;          // 缓冲区指针
    int               flag = 0;         // 结束标志
    KEY               key;
    PCELL             cell;             // 生产消费空间

    index       = 0;
    cell        = (PCELL)args;

    key.str_cur_bit = MIN_KEY_LEN;

    for(i = 0; i < MAX_KEY_LEN; i++)
    {
      if(i < key.str_cur_bit)
      {
        key.str_key_index[i]=0;
        key.str_key[i] = key_word[key.str_key_index[i]];
      }
      else
      {
        key.str_key[i] = 0;
        key.str_key_index[i] = -1;
      }
    }

    if(clock_gettime(CLOCK_REALTIME, &time_start) == -1)
      err_sys("clock_gettime error");

    while(1)
    {
      int first_cur_index = key.str_key_index[0];   // 获取下标
      first_cur_index++;
      int i;

      if(first_cur_index < KEY_COUNT)               // 更新下标
      {
        key.str_key_index[0] = first_cur_index;
        key.str_key[0] = key_word[key.str_key_index[0]];
      }
      else
        flag = key_modify(&key);

      if(cell[index].cell_len + key.str_cur_bit + 1 >  BUFF_SIZE || flag) // 提交缓冲区内容
      {
        if(flag)
          res = 1;
        cell[index].cell_flags = 1;                         // 设置缓冲区内容可读取

        pthread_mutex_unlock(&cell[index].cell_mutex);      // 释放缓冲区
        //printf("生产者释放缓冲区 : %d - %d\n", index, cell[index].cell_len);
        if(customer_flags == 0)                             // 检测是否有等待的写入线程
        {
          customer_flags = 1;
          pthread_cond_signal(&cond);
          //printf("%s\n", "-----激活消费者");
        }
        index = (index+1)%2;

      //  cell[index].cell_len=0;
      //  printf("切换之后 : %d\n", cell[index].cell_len);
      }

      if(flag)
      {
        //printf("%s\n", "生产者结束");
        break;
      }


      if(cell[index].cell_len == 0 || cell[index].cell_flags == 1)
      {
          //printf("生产者请求进入缓冲区 : %d - %d\n", index, cell[index].cell_len);
          pthread_mutex_lock(&cell[index].cell_mutex);       // 获取这个缓冲区的所有权
          //printf("生产者进入缓冲区 : %d - %d\n", index, cell[index].cell_len);
      }

      if(cell[index].cell_flags == 1)                    // 检查缓冲区中是否存有数据
      {
          producer_flags = 0;                           // 设置等待标记
          //printf("%s\n", "生产者阻塞");
          pthread_cond_wait(&cond, &cell[index].cell_mutex);
          //printf("%s\n", "生产者激活");
      }

      buffer = cell[index].cell_key_array + cell[index].cell_len;   // 获取输出缓冲区
      strncpy(buffer, key.str_key, key.str_cur_bit);                // 更新缓冲数据
      //write(STDOUT_FILENO, buffer, key.str_cur_bit);
      buffer[key.str_cur_bit] = '\n';
      cell[index].cell_len += (key.str_cur_bit+1);                  // 更新缓冲内容

    }

  return NULL;
}

// 消费者线程
void * pthread_customer_key(void * args)
{
  int               fd;
  int               index;
  PCELL             cell;             // 生产消费空间

  cell    = (PCELL)args;
  index   = 0;

  // 创建写入文件
  if((fd = open("./doc", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP)) == -1)
    err_sys("open error");

  while(1)
  {
    //printf("消费者请求进入缓冲区 ： %d - %d\n", index, cell[index].cell_len);
    pthread_mutex_lock(&cell[index].cell_mutex);
    //printf("消费者进入缓冲区 ： %d - %d\n", index, cell[index].cell_len);

    if(cell[index].cell_flags == 0)   //说明数据并没有准备好 -- 自身等待
    {
      //printf("%s\n", "消费者阻塞");
      customer_flags = 0;
      pthread_cond_wait(&cond, &cell[index].cell_mutex);
      //printf("%s\n", "消费者激活");
    }

    if(write(fd, cell[index].cell_key_array, cell[index].cell_len) == -1)
      err_sys("write error");

    cell[index].cell_flags = 0;
    cell[index].cell_len = 0;
    memset(cell[index].cell_key_array, 0, sizeof(cell[index].cell_key_array));

    pthread_mutex_unlock(&cell[index].cell_mutex);
    //printf("消费者释放缓冲区 ： %d - %d\n", index, cell[index].cell_len);
    if(producer_flags == 0)
    {
      //printf("%s\n", "-----激活生产者");
      producer_flags = 1;
      pthread_cond_signal(&cond);
    }

    index = (index + 1)%2;
    if(res)
      break;
  }

  //raise(SIGUSR1);
  if(clock_gettime(CLOCK_REALTIME, &time_end) == -1)
    err_sys("clock_gettime error");

  printf("总用时 : %d - %ld\n", time_end.tv_sec-time_start.tv_sec, time_end.tv_nsec-time_start.tv_nsec);

  return NULL;
}

int key_modify(PKEY key)
{
  int i;
  int first_cur_index = key->str_key_index[0];

  if(first_cur_index < KEY_COUNT-1)
    return 0;

  // 从最低位置一次遍历
  for(i = 0; i < MAX_KEY_LEN; i++)
  {
    if(key->str_key_index[i] == KEY_COUNT-1)
    {
      key->str_key_index[i] = 0;
      key->str_key[i] = key_word[key->str_key_index[i]];
    }
    else
    {
      key->str_key_index[i] ++;
      key->str_key[i] = key_word[key->str_key_index[i]];

      if(key->str_cur_bit == i){
          key->str_cur_bit ++;
      }
      break;
    }
  }

  if(i == MAX_KEY_LEN)
    return 1;

  return 0;
}
