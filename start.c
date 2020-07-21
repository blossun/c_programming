#include <stdio.h>

int main() {
    int a, b;
    a = 10;
    b = 3;
    printf("a + b 는 : %d \n", a + b);
    printf("a - b 는 : %d \n", a - b);
    printf("a * b 는 : %d \n", a * b);
    printf("a / b 는 : %d \n", a / b);
    printf("a %% b 는 : %d \n", a % b); //% 는 오직 정수형 데이터에서만 연산이 가능
    // printf("a / b 는 : %f \n", a / b); //해서는 안될 짓
    printf("a / b 는 : %f \n", a / b);

    return 0;
}