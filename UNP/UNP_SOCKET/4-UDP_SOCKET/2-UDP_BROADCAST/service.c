#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/param.h>
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
  struct sockaddr_in  sockaddr, client_srcaddr, *client_dstaddr;
  struct msghdr       recvmessage;
  struct cmsghdr      *recvcontrol;
  struct iovec        iovbuf;
  int                 addrlen, recvlen;
  int                 on;
  char                recvbuff[128];
  char                ipaddr[INET_ADDRSTRLEN];
  void                *controlmsg;



  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    err_sys("socket error");
  on = 1;

  // 加入套接字请求
  if(setsockopt(sockfd, IPPROTO_IP, IP_RECVORIGDSTADDR, &on, sizeof(on)) == -1)
    err_sys("setsockopt error");

  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(8068);
  sockaddr.sin_addr.s_addr = 0;

  if(bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
    err_sys("bind error");

  memset(&recvmessage, 0, sizeof(recvmessage));
  recvmessage.msg_name = &client_srcaddr;
  recvmessage.msg_namelen = sizeof(client_srcaddr);

  iovbuf.iov_base = recvbuff;
  iovbuf.iov_len = sizeof(recvbuff);
  recvmessage.msg_iov = &iovbuf;
  recvmessage.msg_iovlen = sizeof(iovbuf);

  recvmessage.msg_control= malloc(CMSG_SPACE(sizeof(struct sockaddr_in)));
  recvmessage.msg_controllen = CMSG_SPACE(sizeof(struct sockaddr_in));
  recvcontrol = (struct cmsghdr *)CMSG_FIRSTHDR(&recvmessage);
  recvcontrol->cmsg_len    = CMSG_LEN(sizeof(struct sockaddr_in));
  recvcontrol->cmsg_level  = IPPROTO_IP;
  recvcontrol->cmsg_type   = IP_RECVORIGDSTADDR;

  while(1)
  {
    /*
    addrlen = sizeof(client_srcaddr);
    if((recvlen = recvfrom(sockfd, recvbuff, sizeof(recvbuff), 0, (struct sockaddr *)&client_srcaddr, &addrlen)) == -1)
      err_sys("recvfrom error");
    */

    if((recvlen = recvmsg(sockfd, &recvmessage, 0)) == -1)
      err_sys("recvmsg error");
    puts("==================================");
    printf("src addr : %s\n", inet_ntop(AF_INET, &client_srcaddr.sin_addr.s_addr,ipaddr, INET_ADDRSTRLEN));
    printf("src port : %d\n", ntohs(client_srcaddr.sin_port));
    recvcontrol = CMSG_FIRSTHDR(&recvmessage);
    client_dstaddr = (struct sockaddr_in *)CMSG_DATA(recvcontrol);
    printf("dst addr : %s\n", inet_ntop(AF_INET, &client_dstaddr->sin_addr.s_addr,ipaddr, INET_ADDRSTRLEN));
    printf("dst port : %d\n", ntohs(client_dstaddr->sin_port));
    write(STDOUT_FILENO, recvbuff, recvlen);
  }

  close(sockfd);

  return 0;
}
