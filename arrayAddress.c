/* 배열과 포인터 */
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    int* parr = arr;

    printf("sizeof(arr) : %lu \n", sizeof(arr));
    printf("sizeof(parr) : %lu \n", sizeof(parr));

    return 0;
}