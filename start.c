/* 2차원 배열 */
#include <stdio.h>
int main() {
    // int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; //위와 동일

    for (int i=0; i<3; i++) {
        printf("[%d]행 : ", i);
        for (int j=0; j<3; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

  return 0;
}