/* 2차원 배열의 포인터 */
#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    printf("arr : %p , arr + 1 : %p \n", arr, arr + 1);
    
    //int *parr = &arr; // 열의 갯수를 알아야 주소 연산을 할 수 있음. 따라서 컴파일에러가 난다.
    int (*parr)[3]; //가르키는 2차원 배열의 열의 크기를 지정해줘야 한다.
    
    parr = arr; // parr 이 arr 을 가리키게 한다.

    printf("arr[1][0] : %d , *(arr + 1) : %d \n", arr[1][0], *parr[1]);

    printf("arr[1][2] : %d, parr[1][2] : %d, *parr[1]+2 : %d \n", arr[1][2], parr[1][2], *parr[1]+2);
    //printf("*parr[1][2] : %d \n", *parr[1][2]); //오류

    return 0;
}