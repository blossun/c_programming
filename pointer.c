/* 포인터의 포인터 */
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    int (*parr)[3] = &arr; //크기가 3인 배열을 가리키는 포인터
    //int *parr[3]; //int * 원소(포인터) 3개를 가지는 배열을 정의
    int *parr2 = arr;

    printf("arr[1] : %d \n", arr[1]); //2
    printf("parr[1] : %d \n", (*parr)[1]); //2
    printf("parr : %p, arr : %p \n", parr, &arr);
    // printf("(*parr+1) : %d \n", (*parr+1)); //컴파일 에러
    // printf("*(parr+1) : %d \n", *(parr+1)); //컴파일 에러
    printf("*(parr2+1) : %d \n", *(parr2+1)); //2

    return 0;
}