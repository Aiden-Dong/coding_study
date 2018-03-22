// UNIX Domain Socket for service
// 2016-08-28 10 by Saligia

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/un.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// SOL_SOCKET | SCM_RIGHTS
#define UNIX_PATH "/tmp/saligia103142.socket"

void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}
void  err_sys(const char *msg) {
  printf("%s:%s\n", msg, strerror(errno));
  exit(errno);
}

int main(int argc, char*argv[])
{
  int                 sockfd, clienfd;
  int                 addrlen, bufflen;
  struct sockaddr_un  unixaddr, clienaddr;
  struct msghdr       servmsg;
  struct cmsghdr      *msgcontrol;
  struct iovec        clienmsg;
  int                 filefd;
  char                buff[128];

  if(argc != 2)
    err_que("execute fileno");

  if((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) == -1)
    err_sys("socket error");

  if((filefd = open(argv[1], O_RDONLY)) == -1)
    err_sys("open error");

  unlink(UNIX_PATH);
  memset(&unixaddr, 0, sizeof(unixaddr));
  unixaddr.sun_family = AF_LOCAL;
  strncpy(unixaddr.sun_path, UNIX_PATH, strlen(UNIX_PATH));

  if(bind(sockfd, (struct sockaddr *)&unixaddr, sizeof(unixaddr)) == -1)
    err_sys("bind error");


  if(listen(sockfd, 5) == -1)
    err_sys("listen error");

  memset(&servmsg, 0, sizeof(servmsg));
  servmsg.msg_name = NULL;
  servmsg.msg_namelen=0;
  memset(buff, 0, sizeof(buff));
  strncpy(buff, "Hello world", strlen("Hello world"));
  clienmsg.iov_base = buff;
  clienmsg.iov_len = strlen("Hello world");
  servmsg.msg_iov = &clienmsg;
  servmsg.msg_iovlen = 1;
  servmsg.msg_control = malloc(CMSG_SPACE(sizeof(int)));
  servmsg.msg_controllen=CMSG_SPACE(sizeof(int));
  msgcontrol = CMSG_FIRSTHDR(&servmsg);
  msgcontrol->cmsg_len = CMSG_LEN(sizeof(int));
  msgcontrol->cmsg_level = SOL_SOCKET;
  msgcontrol->cmsg_type = SCM_RIGHTS;
  *(int *)CMSG_DATA(msgcontrol) = filefd; // 填充文件描述符


  while(1)
  {
    addrlen = sizeof(clienaddr);
    if((clienfd = accept(sockfd, (struct sockaddr*)&clienaddr, &addrlen)) == -1)
      err_sys("accept error");

    puts("接受到连接");

    if(sendmsg(clienfd, &servmsg, 0) == -1)
      err_sys("sendmsg");

  }
  close(sockfd);
  close(filefd);
  return 0;
}
