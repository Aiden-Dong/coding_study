#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}
void err_sys(const char *msg)
{
  printf("%s : %s \n", msg, strerror(errno));
  exit(errno);
}

int main(int argc, char *argv[])
{
  int               sockfd;
  int               errinfo;
  struct addrinfo   iniaddr, *resaddr, *headaddr;

  if(argc != 3)
    err_que("execu hostname servname");

  iniaddr.ai_flags = AI_CANONNAME;
  iniaddr.ai_family = AF_INET;
  iniaddr.ai_socktype = SOCK_STREAM;
  iniaddr.ai_protocol = IPPROTO_TCP;

  if(errinfo = getaddrinfo(argv[1], argv[2], &iniaddr, &resaddr))
  {
    printf("getaddrinfo error : %s\n", gai_strerror(errinfo));
    exit(0);
  }

  for(headaddr = resaddr; resaddr != NULL; resaddr = resaddr->ai_next)
  {
    if((sockfd = socket(resaddr->ai_family, resaddr->ai_socktype, resaddr->ai_protocol)) == -1)
      continue;
    if(connect(sockfd, resaddr->ai_addr, resaddr->ai_addrlen) == -1)
      connect;
    break;
  }

  if(resaddr == NULL)
  {
    freeaddrinfo(headaddr);
    err_sys("set socket error");
  }

  freeaddrinfo(headaddr);

  if(send(sockfd, "hello world\n", strlen("hello world\n"), 0) == -1)
    err_sys("send error");

  close(sockfd);

  return 0;
}
