#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <net/if.h>
#include <net/if_arp.h>
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
  int                 sockfd;
  struct arpreq       arpmsg;
  struct sockaddr_in  *dstaddr;
  uint8_t             *data;
  uint8_t             *setda;
  uint8_t              ipaddr[INET_ADDRSTRLEN];

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    err_sys("socket error");

  memset(&arpmsg, 0, sizeof(arpmsg));
  dstaddr = (struct sockaddr_in *)&arpmsg.arp_pa;
  memset(dstaddr, 0, sizeof(struct sockaddr_in));
  dstaddr->sin_family = AF_INET;
  if(inet_pton(AF_INET, "192.168.1.0", &dstaddr->sin_addr.s_addr) == -1)
    err_sys("inet_pton error");
  strncpy(arpmsg.arp_dev, "enp0s25", strlen("enp0s25"));

  setda = (uint8_t *)&dstaddr->sin_addr.s_addr;

  for(setda[3] = 1; setda[3] < 255; setda[3]++)
  {
    if(ioctl(sockfd, SIOCGARP, &arpmsg) == -1)
    {
      if(errno == ENXIO)
        continue;
      else
        err_sys("ioctl error");
    }

    printf("%s\t", inet_ntop(AF_INET, &dstaddr->sin_addr.s_addr, ipaddr, INET_ADDRSTRLEN));
    data = &arpmsg.arp_ha.sa_data[0];
    printf("%2x:%2x:%2x:%2x:%2x:%2x\n", data[0], data[1], data[2], data[3], data[4],data[5]);

  }
  return 0;
}
