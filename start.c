/* 문제3 */
// 1000 이하의 3 또는 5 의 배수인 자연수들의 합을 구한다.
#include <stdio.h>
int main() {
    int sum=0;

    for (int i=1; i<=1000; i++) {
        if (i%3==0 || i%5==0) {
            sum += i;
        }
    }

    printf("1000 이하의 3 또는 5 의 배수인 자연수들의 합 : %d\n", sum);

    return 0;
}