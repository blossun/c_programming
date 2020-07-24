/*  2 차원 배열의 각 원소를 1 씩 증가시키는 함수 */
#include <stdio.h>
void add (int (*parr)[2], int row );

int main()
{
    int arr[3][2];

    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    add(arr, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
        }
    }

    return 0;
}

// void add (int (*parr)[2], int row ) { 
void add (int parr[][2], int row ) { //위와 동일 //함수의 인자에서만 허용되는 표현
    //열의 갯수를 여기서 하드코딩하는건 이상한데
    //2차원 배열을 가리키는 포인터
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 2; j++) {
            parr[i][j]++;
        }
    }
}
