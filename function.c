/* function 인자로 포인터 써먹기 */
#include <stdio.h>

void changeValue(int *pi) {
    printf("----- changeValue 함수 안 ------\n");
    printf("pi의 값 : %p \n", pi);
    printf("pi가 가리키는 값 : %d \n", *pi);

    *pi = 3;

    printf("----- changeValue 함수 종료 -----\n");
}

int main() {
    int i = 0;

    printf("i 변수의 주소값 : %p \n", &i);
    printf("호출 이전 i 값 : %d \n", i);
    changeValue(&i);
    printf("호출 이후 i 값 : %d \n", i);

    return 0;
}
