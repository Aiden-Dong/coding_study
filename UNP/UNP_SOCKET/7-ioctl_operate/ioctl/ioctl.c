#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

int main(int argc, char*argv[])
{
  int             sockfd;
  struct ifconf   intermsg;
  struct ifreq    *msgreq;
  uint8_t         *ptr;
  uint8_t         ipaddr[INET_ADDRSTRLEN];

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    err_sys("socket error");

  intermsg.ifc_len = 1024;
  intermsg.ifc_buf = malloc(1024);

  if(ioctl(sockfd, SIOCGIFCONF, &intermsg) == -1)
    err_sys("ioctl error");

  printf("信息大小 :%d\n", intermsg.ifc_len);

  for(ptr = (uint8_t *)intermsg.ifc_req; ptr-(uint8_t*)intermsg.ifc_req <80; ptr+=40)
  {
    msgreq = (struct ifreq *)ptr;
    printf("接口 ：%s\n", msgreq->ifr_name);
    printf("地址 ：%s\n", inet_ntop(AF_INET, &((*(struct sockaddr_in *)&msgreq->ifr_addr)).sin_addr.s_addr, ipaddr, INET_ADDRSTRLEN));
  }

  return 0;
}
