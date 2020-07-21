#include <stdio.h>

int main() {
    /* scanf : 사용자 입력 받기 */
    /* 섭씨 온도를 화씨로 바꾸기 */
    double celsius; //섭씨 온도

    printf("섭씨 온도를 화씨 온도로 바꿔주는 프로그램 입니다. \n");
    printf("섭씨 온도를 입력해 주세요 : ");
    scanf("%lf", &celsius); //double형을 입력받을 때는 무조건 %lf

    printf("섭씨 %f 도는 화씨로 %f 입니다. \n", celsius, 9 * celsius / 5 + 32);
    return 0;
}