//
// Created by norma.eva on 2019-02-15.
//

#ifndef CMAKE_STUDY_PERSION_H
#define CMAKE_STUDY_PERSION_H

#include <string>

using namespace std;

class persion {
private:
    string name;
    int age;
public:
    persion(string name, int age);
    string getName();
    int getAge();
};


#endif //CMAKE_STUDY_PERSION_H
