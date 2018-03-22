// UNIX Domain Socket for service
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

  unlink(UNIX_PATH);
  memset(&unixaddr, 0, sizeof(unixaddr));
  unixaddr.sun_family = AF_LOCAL;
  strncpy(unixaddr.sun_path, UNIX_PATH, strlen(UNIX_PATH));

  if(bind(sockfd, (struct sockaddr *)&unixaddr, sizeof(unixaddr)) == -1)
    err_sys("bind error");


  if(listen(sockfd, 5) == -1)
    err_sys("listen error");

  while(1)
  {
    addrlen = sizeof(clienaddr);

    if((clienfd = accept(sockfd, (struct sockaddr*)&clienaddr, &addrlen)) == -1)
      err_sys("accept error");

    if((bufflen = recv(clienfd, buff, sizeof(buff), 0)) == -1)
      err_sys("recv error");

    if(write(STDOUT_FILENO, buff, bufflen) == -1)
      err_sys("write error");
  }

  return 0;
}
