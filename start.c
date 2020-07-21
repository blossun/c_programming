/* 논리 연산자 */
#include <stdio.h>
int main() {
    int a;
    printf("숫자 입력 : ");
    scanf("%d", &a);

    if (a>=10 && a<20) { //논리합
        printf("%d는 10이상 20미만인 수\n", a);
    }

    int height, weight;
    printf("당신의 키와 몸무게를 각각 입력해 주세요 : ");
    scanf("%d %d", &height, &weight);

    if (height >= 190 || weight >= 100) { //논리곱
        printf("당신은 '거구' 입니다. \n");
    }

    if (!(height >= 190 || weight >= 100)) { //논리부정
        printf("당신은 거구가 아닙니다. \n");
    }

    return 0;
}