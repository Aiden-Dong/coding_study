//
// Created by norma.eva on 2019-02-20.
//

#include "student.h"

extern u_int8_t test;

Student::Student(std::string name, u_int8_t age, std::string v_class)
    :Persion(name,age){
    this->v_class = v_class;
}

std::string Student::getClass() {
    return this->v_class;
}
