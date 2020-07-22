/* swich - case */
#include <stdio.h>

int main() {
    int input;

    printf("마이펫 업그레이드\n");
    printf("무엇을 하실 것인지 입력하세요 \n");
    printf("1. 밥주기 \n");
    printf("2. 씻기기 \n");
    printf("3. 재우기 \n");

    scanf("%d", &input);

    switch(input) {
        case 1:
            printf("냠냠 \n");
            break;
        case 2:
            printf("깨운 \n");
            break;
        case 3:
            printf("zzzz \n");
            break;
        default:
            printf("나 뭐할까? \n");
    }

    return 0;
}