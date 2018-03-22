// UNIX Domain Socket for client
// 2016-08-28 10 by Saligia
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

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
  char                buff[128];

  if((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) == -1)
    err_sys("socket error");

  memset(&unixaddr, 0, sizeof(unixaddr));
  unixaddr.sun_family = AF_LOCAL;
  strncpy(unixaddr.sun_path, UNIX_PATH, strlen(UNIX_PATH));

  if(connect(sockfd, (struct sockaddr *) &unixaddr, sizeof(unixaddr)) == -1)
    err_sys("connect error");

  if(send(sockfd, "hello world\n", strlen("hello world\n"), 0) == -1)
    err_sys("send error");

  return 0;
}
