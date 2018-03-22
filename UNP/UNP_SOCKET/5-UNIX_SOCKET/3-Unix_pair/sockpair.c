#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}

void err_sys(const char *msg)
{
  printf("%s : %s\n", msg, strerror(errno));
  exit(errno);
}

int main(int argc, char *argv[])
{
  int           pid;
  int           sockfd[2];// 令 sockfd[0] 为父进程socket | sockfd[1] 为子进程socket
  char          buff[128];
  int           recvlen;

  if(socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfd) == -1)
    err_sys("socketpair error");

  if((pid = fork()) == -1)
    err_sys("pid error");
  else if(pid == 0) // 子进程
  {
    if(send(sockfd[1], "hello world", strlen("hello world"), 0) == -1)
      err_sys("send error");

    close(sockfd[1]);
    return 0;
  }
  else              // 父进程
  {
    if((recvlen = recv(sockfd[0], buff, sizeof(buff), 0)) == -1)
        err_sys("recv error");

      write(STDOUT_FILENO, buff, recvlen);
  }
}
