#include "public_source.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void err_que(const char *msg)
{
        puts(msg);
        exit(0);
}
void err_sys(const char *msg)
{
        printf("%s : %s\n", msg, strerror(errno));
        //kill(pid, SIGINT);
        exit(0);
}

