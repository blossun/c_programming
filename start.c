#include <stdio.h>

int main() {
    int a;
    int b;
    double c;
    
    a = 10;
    b = 3;
    c = 3;
    // printf("a / b 는 : %f \n", a / b); //해서는 안될 짓. 자료형이 맞지않음
    printf("a / c 는 : %f \n", a / c);
    printf("c / a 는 : %f \n", c / a);

    return 0;
}