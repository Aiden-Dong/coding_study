#include <iostream>
#include "persion/persion.h"

int main(int argc, char * argv[]) {
    persion  persion =  persion("saligia", 31);
    std::cout << persion.getName() << std::endl;
    std:cout << persion.getAge() << std::endl;

    return 0;
}