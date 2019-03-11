//
// Created by norma.eva on 2019-03-01.
//


#include "test_signal.h"


void sleep1(int sec)
{
    if(signal(SIGALRM, alarm_func) == SIG_ERR)
    {
        exit(0);
    }
    alarm(sec);
    pause();
}

static void calc_long_time()
{
    std::cout << "start calc ..." << std::endl;

    for(int i = 0; i < 10000000; i ++)
    {
        for(int j = 0; j < 30000; j++)
        {
            i+j;
        }
    }
    std::cout << "finish calc ..." << std::endl;
}

static void alarm_func(int signo)
{
    std::cout << "sleep finished" << std::endl;
}


void start()
{
    calc_long_time();
}