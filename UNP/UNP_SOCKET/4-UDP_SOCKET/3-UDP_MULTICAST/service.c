#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/param.h>
#include <net/if.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void err_sys(const char *msg)
{
  printf("%s : %s\n",msg, strerror(errno));
  exit(errno);
}
void err_que(const char *msg)
{
    puts(msg);
    exit(0);
}
int main(int argc, char*argv[])
{
  int                   sockfd;
  struct sockaddr_in    sockaddr, *multip, clientaddr;
  char                  buff[1024];
  int                   recvlen;
  int                   addrlen;
  struct group_req      multaddr;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    err_sys("socket error");

    // 加入多播组
   multaddr.gr_interface = if_nametoindex("enp0s25");
   multip = (struct sockaddr_in *)&multaddr.gr_group;
   multip->sin_family = AF_INET;
   inet_pton(AF_INET, "224.1.1.5", &multip->sin_addr.s_addr);
   if(setsockopt(sockfd, IPPROTO_IP, MCAST_JOIN_GROUP, &multaddr, sizeof(multaddr)) == -1)
    err_sys("setsockopt");

   memset(&sockaddr, 0, sizeof(sockaddr));
   sockaddr.sin_family = AF_INET;
   sockaddr.sin_port = htons(8068);
   sockaddr.sin_addr.s_addr = 0;

   if(bind(sockfd, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) == -1)
      err_sys("bind error");

  addrlen = sizeof(clientaddr);
  if((recvlen = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&clientaddr, &addrlen)) == -1)
    err_sys("recvfrom error");

  if(write(STDOUT_FILENO, buff, recvlen) == -1)
    err_sys("write error");

  return 0;
}
