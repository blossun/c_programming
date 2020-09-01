/* 상수 포인터? */
#include <stdio.h>
int main() {
    int a;
    int b;
    // 1번 경우
    // const int* pa = &a; //const int *pa 와 동일

    // *pa = 3; // 올바르지 않은 문장
    // pa = &b; // 올바른 문장


    // 2번 경우
    // int* const pa = &a; //const 위치가 다름

    // *pa = 3; // 올바른 문장
    // pa = &b; // 올바르지 않은 문장

    // 3번 경우
    const int *const pa = &a;

    *pa = 3; // 올바르지 않은 문장
    pa = &b; // 올바르지 않은 문장
    return 0;
}