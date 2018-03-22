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

void err_que(const char *msg);
void err_sys(const char *msg);

int main(int argc, char *argv[])
{
  int                 sockfd, clientfd;
  int                 errinfo;
  int                 addrlen;
  int                 recvlen;
  char                ipaddr[INET_ADDRSTRLEN];
  char                clientmsg[128];
  struct addrinfo     iniaddr, *resaddr, *headaddr;
  struct sockaddr_in  clientaddr;

  if(argc != 2)
    err_que("exec servicename");

  memset(&iniaddr, 0, sizeof(iniaddr));
  iniaddr.ai_flags = AI_PASSIVE;
  iniaddr.ai_family = AF_INET;
  iniaddr.ai_protocol=IPPROTO_TCP;
  iniaddr.ai_socktype = SOCK_STREAM;

  if(errinfo = getaddrinfo(NULL, argv[1], &iniaddr, &resaddr))
  {
    printf("getaddrinfo error : %s\n", gai_strerror(errinfo));
    exit(0);
  }

  headaddr = resaddr;

  for(; resaddr != NULL; resaddr=resaddr->ai_next)
  {
    if((sockfd = socket(resaddr->ai_family, resaddr->ai_socktype, resaddr->ai_protocol)) == -1)
      continue;
    if(bind(sockfd, resaddr->ai_addr, resaddr->ai_addrlen) == -1)
      continue;
    break;
  }
  if(resaddr == NULL)
  {
    freeaddrinfo(headaddr);
    err_sys("set socket error");
  }

  printf("set socket sucess : %s\n", resaddr->ai_canonname);
  printf("addr : %s\n", inet_ntop(AF_INET, &(((struct sockaddr_in *)(resaddr->ai_addr))->sin_addr.s_addr), ipaddr, INET_ADDRSTRLEN));
  printf("port : %d\n", ntohs(((struct sockaddr_in *)(resaddr->ai_addr))->sin_port));
  freeaddrinfo(headaddr);

  if(listen(sockfd, 5) == -1)
    err_sys("listen error");

  addrlen = sizeof(clientaddr);
  if((clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen)) == -1)
    err_sys("accept error");

  printf("瀹㈡埛鏁版嵁鍒拌揪:\n");
  printf("addr : %s\n", inet_ntop(AF_INET, &clientaddr.sin_addr, ipaddr, INET_ADDRSTRLEN));
  printf("prot : %d\n", ntohs(clientaddr.sin_port));

  if((recvlen = recv(clientfd, clientmsg, sizeof(clientmsg), 0)) == -1)
    err_sys("recvlen error");

  write(STDOUT_FILENO, clientmsg, recvlen);

  return 0;
}
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
