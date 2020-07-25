/* 버퍼비우기 */
#include <stdio.h>

int main() {
    int num;
    char str[30];

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    // fflush(stdin); // 버퍼비우기 //비추
    printf("%c", getchar());

    printf("문자열을 입력하세요 : ");
    scanf("%s", str); 

    return 0;
}
