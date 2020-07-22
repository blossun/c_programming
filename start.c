/* do-while 1~100합 */
#include <stdio.h>
int main() {
    // int i,sum=0; //둘다 0으로 초기화 안되네...
    int i=0, sum=0;
    // int i, sum;
    // i = sum = 0;
    printf("i : %d, sum : %d \n", i, sum);

    do {
        sum += i;
        i++;
    }while(i<=100);

    printf("1~100 까지의 합 : %d \n", sum);

    return 0;
}