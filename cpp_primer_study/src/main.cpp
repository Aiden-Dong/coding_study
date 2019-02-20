#include <iostream>
#include "class/persion.h"

int main() {

    Persion persion = Persion("saligia", 20);
    persion.show();
    STRPERSION str_persion = persion;
    printf("name : %s\n", str_persion.name.data());
    printf("age : %d\n", str_persion.age);
    return 0;
}