//
// Created by norma.eva on 2019-02-15.
//

#include "persion.h"

persion::persion(string name, int age) {
    this->name = name;
    this->age = age;
}

int persion::getAge() {
    return this->age;
}

string persion::getName() {
    return this->name;
}
