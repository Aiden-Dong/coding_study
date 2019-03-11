/**
 * <pre>
 *   测试 NIO 在多路复用中的使用场景
 * </pre>
 *
 * @user : aiden
 * @date : 2019-03-05
 */

#include "nio.h"
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/conf.h>
#include <sys/ipc.h>
#include <errno.h>

void nio_start()
{
    int fd;
    fd_set read_set;
    char strarr[10240];
    struct timeval timeout;
    struct ipc_perm perm;

    fd = open("/Users/saligia/tmp/core.log", O_RDONLY | O_NONBLOCK); // 非阻塞的读取

    if(fd == -1)
    {
        std::cout << "open file error : " << strerror(errno) << std::endl;
        return;
    }

    FD_ZERO(&read_set);
    FD_SET(fd, &read_set);

    timeout.tv_usec = 0;
    timeout.tv_sec = 1;

    while(true)
    {

        int n;
        if((n = select(fd+1, &read_set, NULL, NULL, &timeout)) == -1)
        {
            std::cout << "select ctrl error : " << strerror(errno) << std::endl;
            return;
        }

        timeout.tv_usec = 0;
        timeout.tv_sec = 1;

        if(n == 0)
        {
            std::cout << "no ready for read" << std::endl;
            continue;
        }

        std::cout << "=======================================" << std::endl;

        memset(strarr, 0, sizeof(strarr));
        int nbyte = read(fd, strarr, sizeof(strarr));

        std::cout << "===== read : " << nbyte  << " ============"<< std::endl;

        if(nbyte == -1)
        {
            std::cout << "read error :" << strerror(errno) << std::endl;
            return;
        }

        if(nbyte == 0)
        {
            return;
        }

        if(write(STDOUT_FILENO, strarr, nbyte) == -1)
        {
            std::cout << "write error :" << strerror(errno) << std::endl;
            return;
        }
    }
}


