/* 포인터 배열 */
#include <stdio.h>

int main() {
    char arr[2][3][4] =
    {
        {
            {'a', 'b', 'c', 'd'},
            {'e', 'f', 'g', 'h'},
            {'i', 'j', 'k', 'l'}
        },
        {
            {'m', 'n', 'o', 'p'},
            {'q', 'r', 's', 't'},
            {'u', 'v', 'w', 'x'}
        }
    };

    char (*parr)[3][4] = arr;
    printf("arr[0] : %p, *parr[2] : %p \n", arr[0], parr);
    printf("arr[1] : %p, *parr[1] : %p \n", arr[1], parr[1]); //arr[0]과 12byte 차이
    printf("arr[1][0][0] : %p, *parr[1] : %p \n", &arr[1][0][0], parr[1]);
    printf("arr[1][0][0] : %c, *parr[1] : %s \n", arr[1][0][0], *parr[1]); //*parr[1]이 m~x까지 읽고다시 m까지 출력된다.
    printf("arr[1][0][0] : %c, *parr[1] : %c \n", arr[1][0][0], *parr[1][0]); // m

    printf("arr[1][1][2] : %p, *parr[1] : %p \n", &arr[1][1][2], parr[1]+1+2); //arr[1]과 6byte 차이 //포인터 잘못된 접근
    printf("arr[1][1][2] : %p, *parr[1] : %p \n", &arr[1][1][2], parr[1][1]+2); //올바른 접근
    printf("arr[1][1][2] : %c, *parr[1] : %c \n", arr[1][1][2], *parr[1][1]+2);

    printf("arr[1][2][3] : %p, *parr[1] : %c \n", &arr[1][2][3], *parr[1][2]+3);
    printf("arr[1][2][3] : %c, *parr[1] : %c \n", arr[1][2][3], *parr[1][2]+3);

    return 0;
}