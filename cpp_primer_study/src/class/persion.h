//
// Created by norma.eva on 2019-02-20.
//

#ifndef CPP_PRIMER_STUDY_PERSION_H
#define CPP_PRIMER_STUDY_PERSION_H
#include <string>
#include <iostream>

typedef struct {
    std::string name;
    u_int8_t age;
}STRPERSION, *PSTRPERSION;

class Persion{
private:
    std::string name;
    u_int8_t age;
public:
    Persion(std::string name, u_int8_t age);
    std::string getName();
    u_int8_t getAge();

    void show();

    // 转换函数
    operator STRPERSION();

    // 重载运算符
    STRPERSION operator = (const STRPERSION str_persion);

    ~Persion();
};

#endif //CPP_PRIMER_STUDY_PERSION_H
