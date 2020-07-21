#include <stdio.h>

int main() {
    /* 데이터 크기 */
    unsigned int b = -1; //-1 은 0xFFFFFFFF 로 표현 ( +1:00000001 -반전-> FFFFFFFE -- +1 --> FFFFFFFF)
    printf("b 에 들어있는 값을 unsigned int 로 해석했을 때 값 : %u \n", b);

    b = 4294967295;
    printf("b : %u \n", b);

    b++;
    printf("b : %u \n", b);
    return 0;
}