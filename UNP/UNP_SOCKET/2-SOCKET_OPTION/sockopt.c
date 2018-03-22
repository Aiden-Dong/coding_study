#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void err_sys(const char* msg)
{
  printf("%s : %s\n", msg, strerror(errno));
  exit(0);
}

void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}

int getsock_msg(int sockfd, int level, int optname);

int main(int argc, char *argv[])
{
  int                 sockfd;
  struct timeval      timeout;
  struct sockaddr_in  seraddr;
  struct linger       cloling;
  int                 optlen;

  if(argc != 2)
    err_que("sockopt.out ipaddr");

  if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    err_sys("socket error");

  // 缓冲区问题
  printf("发送缓冲区的大小 : %d\n", getsock_msg(sockfd, SOL_SOCKET, SO_SNDBUF));
  printf("接受缓冲区的大小 : %d\n", getsock_msg(sockfd, SOL_SOCKET, SO_RCVBUF));
  printf("发送缓冲区最低水位: %d\n", getsock_msg(sockfd, SOL_SOCKET, SO_SNDLOWAT));
  printf("接受缓冲区最低水位: %d\n", getsock_msg(sockfd, SOL_SOCKET, SO_RCVLOWAT));

  // 超时问题
  optlen = sizeof(timeout);
  if(getsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, &optlen) == -1)
    err_sys("getsockopt error");
  printf("接受超时 : %d -- %d\n", timeout.tv_sec, timeout.tv_usec);
  optlen = sizeof(timeout);
  if(getsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, &optlen) == -1)
    err_sys("getsockopt error");
  printf("发送超时 : %d -- %d\n", timeout.tv_sec, timeout.tv_usec);

  cloling.l_onoff = 1;  // 开启 RST 功能
  cloling.l_linger = 0;

  if(setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &cloling, sizeof(cloling)) == -1)
    err_sys("setsockopt error");

  memset(&seraddr, 0, sizeof(seraddr));
  seraddr.sin_family = AF_INET;
  seraddr.sin_port = htons(8068);
  inet_pton(AF_INET, argv[1], (void *)&seraddr.sin_addr.s_addr);

  if(connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)) == -1)
    err_sys("connect");

  if(send(sockfd, "hello world\n", strlen("hello world\n"), 0) == -1)
    err_sys("send error");

  close();// 服务器返回读错误

  return 0;
}

int getsock_msg(int sockfd, int level, int optname)
{
    int             optval;
    int             optlen;
    struct  timeval timeout;


    optlen = sizeof(optval);
    if(getsockopt(sockfd, level, optname, &optval, &optlen) == -1)
      err_sys("getsockopt error");

      return optval;
}
/*
=======================================================================================================================================
-- 三次握手
21:11:06.518897 IP (tos 0x0, ttl 64, id 12544, offset 0, flags [DF], proto TCP (6), length 60)
    192.168.1.86.50851 > 192.168.1.80.8068: Flags [S], cksum 0x8425 (incorrect -> 0x6b76),
    seq 1291375098, win 29200, options [mss 1460,sackOK,TS val 7201018 ecr 0,nop,wscale 7], length 0

21:11:06.519962 IP (tos 0x0, ttl 64, id 0, offset 0, flags [DF], proto TCP (6), length 60)
    192.168.1.80.8068 > 192.168.1.86.50851: Flags [S.], cksum 0xc5b9 (correct),
    seq 4223158671, ack 1291375099, win 14480, options [mss 1460,sackOK,TS val 3643821 ecr 7201018,nop,wscale 6], length 0

21:11:06.519981 IP (tos 0x0, ttl 64, id 12545, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.1.86.50851 > 192.168.1.80.8068: Flags [.], cksum 0x841d (incorrect -> 0x2c2f),
     seq 1, ack 1, win 229, options [nop,nop,TS val 7201019 ecr 3643821], length 0

-- 数据交互
21:11:06.520013 IP (tos 0x0, ttl 64, id 12546, offset 0, flags [DF], proto TCP (6), length 64)
    192.168.1.86.50851 > 192.168.1.80.8068: Flags [P.], cksum 0x8429 (incorrect -> 0x9a42),
    seq 1:13, ack 1, win 229, options [nop,nop,TS val 7201019 ecr 3643821], length 12

--客户端以 RST的方式返回错误
21:11:06.520023 IP (tos 0x0, ttl 64, id 12547, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.1.86.50851 > 192.168.1.80.8068: Flags [R.], cksum 0x841d (incorrect -> 0x0d88),
    seq 13, ack 1, win 229, options [nop,nop,TS val 0 ecr 3643821], length 0

-- 服务器对 此数据的上一次数据的 ACK  -- 之后服务器监测到 RST 后中止交互， 不再发送任何数据
21:11:06.520933 IP (tos 0x0, ttl 64, id 53310, offset 0, flags [DF], proto TCP (6), length 52)
    192.168.1.80.8068 > 192.168.1.86.50851: Flags [.], cksum 0x2c24 (correct),
     seq 1, ack 13, win 227, options [nop,nop,TS val 3643822 ecr 7201019], length 0

-- 客户端对 ACK 信号的 响应 RST
21:11:06.520970 IP (tos 0x0, ttl 64, id 25848, offset 0, flags [DF], proto TCP (6), length 40)
    192.168.1.86.50851 > 192.168.1.80.8068: Flags [R], cksum 0x26c2 (correct),
    seq 1291375111, win 0, length 0
=======================================================================================================================================
*/
