/* 문제4 */
// 1000000 이하의 피보나치 수열 ( N 번째 항이 N - 1 번째 항과 N - 2 번째 항으로 표현되는 수열, 시작은 1,1,2,3,5,8,...) 의 짝수 항들의 합을 구한다
#include <stdio.h>

int pibo(int n) {
    if (n==1 || n==2) {
        return 1;
    }
    return pibo(n-1) + pibo(n-2);
}

int main() {
    int sum = 0;
    
    for (int i=1; i<=10; i++) {
        int number = pibo(i);
        printf("%d, ", number);
        sum += number;
    }

    return 0;
}