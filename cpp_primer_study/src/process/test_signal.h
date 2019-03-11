//
// Created by norma.eva on 2019-03-01.
//

#ifndef CPP_PRIMER_STUDY_TEST_SIGNAL_H
#define CPP_PRIMER_STUDY_TEST_SIGNAL_H

#include <signal.h>
#include "unistd.h"
#include <cstdlib>
#include <iostream>

void sleep1(int sec);

static void calc_long_time();
static void alarm_func(int signo);


void start();


#endif //CPP_PRIMER_STUDY_TEST_SIGNAL_H
