/* 이상한 scanf - %s는 ?? */
#include <stdio.h>

int main() {
    int num;
    char str[30];

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    printf("문자열을 입력하세요 : ");
    scanf("%s", str); 

    return 0;
}
