/* 배열과 포인터 */
#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* parr;
    int i;
    parr = &arr[0];

    for (int i=0; i<10; i++) {
        printf("arr[%d] 의 주소값 : %p \n", i, &arr[i]);
        printf("(parr + %d) 의 주소값 : %p \n", i, (parr+i));

        if (&arr[i] == (parr+i)) {
            /* 만일 (parr + i) 가 성공적으로 arr[i] 를 가리킨다면 */
            printf(" --> 일치 \n");
        } else {
            printf(" --> 불일치 \n");
        }
    }

    // 포인터로 배열의 인덱스에 접근하는 방법
    printf("arr[3] = %d, *(parr+3) = %d \n", arr[3], *(parr+3));

    return 0;
}