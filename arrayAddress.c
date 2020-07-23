/* [] 연산자 */
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    printf("3[arr] : %d \n", 3[arr]);
    printf("*(3+arr) : %d \n", *(3+arr));

    return 0;
}