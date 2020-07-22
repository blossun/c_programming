/* 문제2 */
// *****
//  ***
//   *
#include <stdio.h>
int main() {
    int n;
    printf("숫자 N 입력 : ");
    scanf("%d", &n);

    int width = n*2-1;

    for (int i=n; i>=1; i--) { //증가순서만 변경

        for (int j=1; j<=(n-i+1); j++) {
            printf(" ");
        }

        for (int j=1; j<=(i*2-1); j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}