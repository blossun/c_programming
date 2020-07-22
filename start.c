/* 상수 */
#include <stdio.h>
int main() {
    int a = 3;
    const int b = a;

    char c[b]; //상수로 배열의 크기지정 ?? 될까?? 된다..!

    for (int i=0; i<b; i++) {
        c[i] = 65 + i;
    }

    for (int i=0; i<b; i++) {
        printf("c[%d] : %c\n", i, c[i]);
    }

    return 0;
}