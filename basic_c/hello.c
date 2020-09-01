#include <stdio.h>

int main() {
    int a;
    a = 127;
    printf("a의 값은 %d 진수로 %o 입니다.\n", 8, a);
    printf("a의 값은 %d 진수로 %d 입니다.\n", 10, a);
    printf("a의 값은 %d 진수로 %x 입니다.\n", 16, a);

    // 실수형 변수
    // 그냥 f 를 안 붙이고 float a = 3.141592 로 하면 이를 double 형으로 인식하여 문제가 생길 수 있습니다. 
    // 따라서, float 형이라는 것을 확실히 표시해 주기 위해 f 를 끝에 붙이는 것
    float aa = 3.141592f;
    double b = 3.141592;
    int c = 123;
    int d = 123456;
    printf("a : %.2f \n", aa);
    printf("b : %6.3f \n", b);
    printf("c : %5d \n", c);
    printf("d : %5d \n", d); //자릿수 맞추기가 무조건이 아님
    return 0;
}