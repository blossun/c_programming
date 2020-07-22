/* 문제4 */
// 값이 1000000 이하의 피보나치 수열 ( N 번째 항이 N - 1 번째 항과 N - 2 번째 항으로 표현되는 수열, 시작은 1,1,2,3,5,8,...) 의 숫자가 짝수인 항들의 합을 구한다
// (N항이 1000000이 아님)
#include <stdio.h>

int pibo(int n) { //n=40이후 부터 재귀함수가 너무 느림....
    if (n==1 || n==2) {
        return 1;
    }
    return pibo(n-1) + pibo(n-2);
}

int main() {
    unsigned long sum = 0;
    
    for (int i=1; ; i++) {
        int number = pibo(i);
        if (number > 1000000) {
            break;
        }
        printf("%i : %d, \n ", i, number);
        if (number%2==0) {
            sum += number;
        }
    }

    printf("\n1000000 이하의 피보나치 수열의 값이 짝수인 항들의 합 : %lu", sum);

    return 0;
}