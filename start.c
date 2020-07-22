/* & 연산자, 포인터의 시작 */
#include <stdio.h>
int main() {
    int* p;
    int a=2;

    p = &a;

    printf("포인터 p에 들어있는 값 : %p \n", p); //%p : 16진수로 출력
    printf("int 변수 a가 저장된 주소값 : %p \n", &a);

    return 0;
}