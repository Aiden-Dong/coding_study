#include "unknow_unix_socket.h"
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/msg.h>
/**
 * <pre>
 * </pre>
 *
 * @user : aiden
 * @date : 2019-03-08
 */

static void sys_error(const char * mesage)
{

    std::cout << mesage << " : " << strerror(errno) << std::endl;
    exit(-1);
}

static void client_process(int signo)
{
    int status;
    if(waitpid(0, &status, 0) == -1)
    {
        sys_error("waitpid error");
    }

    if(WIFEXITED(status))
    {
        std::cout << "client process exit success" << std::endl;
    }
}

static void parent_ctrl(int fd)
{
    char message[512];

    if(write(fd, "I'm parent", sizeof("I'm parent")) == -1)
    {
        sys_error("write error");
    }

    memset(message, 0, sizeof(message));
    int len = read(fd, message, sizeof(message));

    if(len == -1){
        sys_error("read error");
    }

    std::cout << "from client message : " << message << std::endl;
    pause();
}
static void client_ctrl(int fd)
{
    char message[512];

    memset(message, 0, sizeof(message));
    int len = read(fd, message, sizeof(message));

    if(len == -1){
        sys_error("read error");
    }

    std::cout << "from parent message : " << message << std::endl;

    if(write(fd, "I'm client", sizeof("I'm client")) == -1)
    {
        sys_error("write error");
    }
}

void unsock_start()
{
    int fd[2];
    struct sigaction action;
    sigset_t sigset1;

    if(socketpair(AF_UNIX, SOCK_STREAM, 0, fd) == -1)
    {
        sys_error("socketpair error");
    }

    sigfillset(&sigset1);
    action.sa_mask = sigset1;
    action.sa_flags = SA_RESETHAND | SA_NOCLDSTOP;
    action.__sigaction_u.__sa_handler = client_process;

    if(sigaction(SIGCHLD, &action, nullptr) == -1)
    {
        sys_error("sigaction error");
    }

    pid_t pid = fork();
    if(pid == -1)
    {
        sys_error("fork error");
    }

    // 子进程
    if(pid == 0)
    {
        client_ctrl(fd[0]);
    }

    else
    {
        parent_ctrl(fd[1]);
    }

}