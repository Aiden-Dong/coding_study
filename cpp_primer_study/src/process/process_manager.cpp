//
// Created by norma.eva on 2019-02-27.
//

#include "process_manager.h"
#include <iostream>
#include <string>

extern char ** environ;

ProcessMananger::ProcessMananger() {

}

void process_init() {
    atexit(exit_prepare);
}

void get_environs() {
    for (int i = 0; i < sizeof(environ); i++){
        std::cout << "env = " << environ[i] << std::endl;
    }
}

void reset_environs(){
    char ** tmp_environ = new char* [4];

    for (int i = 0; i < 4; i++){
        tmp_environ[i] = new char[20];
        memset(tmp_environ[i], 0, sizeof(tmp_environ[i]));
        std::string str = "hello-" + std::to_string(i) + "=" + std::to_string(i);
        memcpy(tmp_environ[i], str.data(), strlen(str.data()));
        std::cout << str << std::endl;
    }

    environ = tmp_environ;

}

static void exit_prepare(){
    std::cout << "exit now" << std::endl;
}