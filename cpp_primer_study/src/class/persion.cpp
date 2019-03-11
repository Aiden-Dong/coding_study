#include "persion.h"

u_int8_t test=1;

Persion::Persion(std::string name, u_int8_t age) {
    this->name = name;
    this->age = age;
}

std::string Persion::getName() {
    return this->name;
}

u_int8_t Persion::getAge() {
    return this->age;
}

void Persion::show() {
    printf("name : %s\n", this->name.data());
    printf("age : %d\n", this->age);
}

Persion::operator STRPERSION(){
    STRPERSION str_persion = {this->name, this->age};
    return str_persion;
}

STRPERSION Persion::operator=(STRPERSION str_persion) {
    return Persion(str_persion.name, str_persion.age);
}

Persion::~Persion() {
}