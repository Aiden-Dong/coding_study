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
* 服务器
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
  int                 errinfo;
  int                 recvlen;
  int                 addrlen;
  char                recvmsg[128];
  struct addrinfo     iniaddr, *resaddr, *headaddr;
  struct sockaddr_in  client_addr;


  if(argc != 2)
    err_que("exec servname");

  memset(&iniaddr, 0, sizeof(iniaddr));
  iniaddr.ai_flags = AI_PASSIVE;
  iniaddr.ai_family = AF_INET;
  iniaddr.ai_socktype = SOCK_DGRAM;
  iniaddr.ai_protocol = IPPROTO_UDP;

  if(errinfo = getaddrinfo(NULL, argv[1], &iniaddr, &resaddr))
  {
    printf("getaddrinfo error : %s\n", gai_strerror(errinfo));
    exit(0);
  }

  for(headaddr = resaddr; resaddr != NULL; resaddr = resaddr->ai_next)
  {
    if((sockfd = socket(resaddr->ai_family, resaddr->ai_socktype, resaddr->ai_protocol)) == -1)
      continue;

    if(bind(sockfd, resaddr->ai_addr, resaddr->ai_addrlen) == -1)
      continue;

    break;
  }

  freeaddrinfo(headaddr);

  if(resaddr == NULL)
    err_sys("set socket error");

  while(1)
  {
    addrlen = sizeof(client_addr);
    if((recvlen = recvfrom(sockfd, recvmsg, sizeof(recvmsg), 0, (struct sockaddr *)&client_addr, &addrlen)) == -1)
      err_sys("recvfrom error");

    write(STDOUT_FILENO, recvmsg, recvlen);

  }

  close(sockfd);

  return 0;
}
