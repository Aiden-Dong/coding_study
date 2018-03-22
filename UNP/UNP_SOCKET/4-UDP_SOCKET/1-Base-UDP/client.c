#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*
* 客户端
*/
void err_sys(const char *msg)
{
  printf("%s : %s\n", msg, strerror(errno));
  exit(0);
}
void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}

int main(int argc, char *argv[])
{
  int                 sockfd;
  int                 sockerr, sockoptlen;
  int                 errinfo;
  int                 recvlen;
  int                 addrlen;
  char                recvmsg[128];
  struct addrinfo     iniaddr, *resaddr, *headaddr;
  struct sockaddr_in  *client_addr;

  if(argc != 3)
    err_que("exec hostname servname");

  memset(&iniaddr, 0, sizeof(iniaddr));
  iniaddr.ai_flags = AI_CANONNAME;
  iniaddr.ai_family = AF_INET;
  iniaddr.ai_socktype = SOCK_DGRAM;
  iniaddr.ai_protocol = IPPROTO_UDP;

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
      continue;

    //if(sendto(sockfd,"hello world\n", strlen("hello world\n"), 0, resaddr->ai_addr, resaddr->ai_addrlen) == -1)
      //continue;
    break;
  }

  if(resaddr == NULL)
    err_sys("set socket error");

  freeaddrinfo(headaddr);



  if(send(sockfd, "hello world\n", strlen("hello world\n"), 0) == -1)
    err_sys("send error");

  sockoptlen = sizeof(sockerr);
  if(getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &sockerr, &sockoptlen) == -1)
    err_sys("getsockopt error");

  printf("recv error %s\n", strerror(errno));

  close(sockfd);
  return 0;
}
