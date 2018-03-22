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

void err_sys(const char *msg)
{
  printf("%s : %s\n", msg, strerror(errno));
  exit(0);
}

int main(int argc, char *argv[])
{
  int                 sockfd;
  int                 sockopt;
  struct sockaddr_in  sockaddr;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    err_sys("sockfd error");

  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port   = htons(8068);
  inet_pton(AF_INET, "224.1.1.5", &sockaddr.sin_addr.s_addr);


  if(sendto(sockfd, "hello world\n", strlen("hello world\n"), 0, (struct sockaddr *)&sockaddr, sizeof(struct sockaddr)) == -1)
    err_sys("sendto error");

  close(sockfd);

  return 0;
}
