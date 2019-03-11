#include <iostream>
#include <signal.h>
#include <zconf.h>
#include "src/process/unknow_unix_socket.h"
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int main() {

    unsock_start();

    return 0;
}

