#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
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
void alarm_sig(int signo);

int main(int argc, char*argv[])
{
  int                   sockfd;
  struct sockaddr_in    sockaddr;
  struct sigaction      alarmact;

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    err_sys("socket error");

  memset(&alarmact, 0, sizeof(alarmact));
  alarmact.sa_handler = alarm_sig;
  if(sigprocmask(SIG_BLOCK, NULL, &alarmact.sa_mask) == -1)
    err_sys("sigprocmask error");
  sigaddset(&alarmact.sa_mask, SIGALRM);
  alarmact.sa_flags   = SA_INTERRUPT;

  if(sigaction(SIGALRM, &alarmact, NULL) == -1)
    err_sys("sigaction error");

  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(8068);
  inet_pton(AF_INET, argv[1], &sockaddr.sin_addr.s_addr);

  alarm(1);
  if(connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
  {
    if(errno == EINTR){
      printf("鏃堕棿瓒呮椂\n");
      exit(ETIMEDOUT);
    }

    else
      err_sys("connect error");
  }
  alarm(0);

  close(sockfd);
  return 0;
}
void alarm_sig(int signo)
{
  return;
}
