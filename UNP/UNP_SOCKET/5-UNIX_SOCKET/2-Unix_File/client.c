// UNIX Domain Socket for client
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
  int                 filefd;
  int                 recvlen;
  struct msghdr       servmsg;
  struct cmsghdr      *cmsgcontrol;
  struct sockaddr_un  unixaddr, clienaddr;
  struct iovec        clienmsg;
  char                filebuff[128];
  char                buff[128];

  if((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) == -1)
    err_sys("socket error");

  memset(&unixaddr, 0, sizeof(unixaddr));
  unixaddr.sun_family = AF_LOCAL;
  strncpy(unixaddr.sun_path, UNIX_PATH, strlen(UNIX_PATH));

  if(connect(sockfd, (struct sockaddr *) &unixaddr, sizeof(unixaddr)) == -1)
    err_sys("connect error");

  memset(&servmsg, 0, sizeof(servmsg));
  servmsg.msg_name=NULL;
  servmsg.msg_namelen=0;
  clienmsg.iov_base = buff;
  clienmsg.iov_len = sizeof(buff);
  servmsg.msg_iov = &clienmsg;
  servmsg.msg_iovlen = 1;
  servmsg.msg_control = malloc(CMSG_SPACE(sizeof(int)));
  servmsg.msg_controllen=CMSG_SPACE(sizeof(int));

  if(recvmsg(sockfd, &servmsg, 0) == -1)
    err_sys("recvmsg error");

  cmsgcontrol = CMSG_FIRSTHDR(&servmsg);
  if(cmsgcontrol->cmsg_len == CMSG_LEN(sizeof(int)) && cmsgcontrol->cmsg_level == SOL_SOCKET && cmsgcontrol->cmsg_type == SCM_RIGHTS)
  {
    filefd = *(int *)CMSG_DATA(cmsgcontrol);

    while (recvlen = read(filefd, filebuff, sizeof(buff)))
    {
      if(recvlen == -1)
        err_sys("read error");

      write(STDOUT_FILENO, filebuff, recvlen);

    }
  }


  close(filefd);
  close(sockfd);
  free(cmsgcontrol);
  return 0;
}
