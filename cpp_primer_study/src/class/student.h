//
// Created by norma.eva on 2019-02-20.
//

#ifndef CPP_PRIMER_STUDY_STUDENT_H
#define CPP_PRIMER_STUDY_STUDENT_H

#include "persion.h"

class Student : Persion {
private:
    std::string v_class;
public:
    Student(std::string name, u_int8_t age, std::string v_class);

    std::string getClass();
};


#endif //CPP_PRIMER_STUDY_STUDENT_H
