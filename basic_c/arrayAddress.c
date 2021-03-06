/* 포인터 이용하기 */
#include <stdio.h>

int main() {
    int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};

    //arr 은 배열의 첫 번째 원소를 가리키는 포인터로 변환되고, 그 원소의 타입이 int 이므로, 포인터의 타입은 int*
    // 따라서, parr 을 통해서 arr 을 이용했을 때와 동일하게 배열의 원소에 마음껏 접근할 수 있게 된다.
    int *parr = arr;
    int sum = 0;

    while (parr - arr <= 9) {
        sum += (*parr);
        parr++; // '포인터가 가리키는 타입의 크기'만큼 더해진다. 즉, int 형 포인터 이므로 4 가 더해지게되서, 배열의 그 다음 원소를 가리킬 수 있게 됩니다.
    }

    // for (int i=0; i<9; i++) {
    //     sum += (*parr);
    //     arr += 4;  //오류
    //     parr = arr;
    // }

    printf("내 시험 점수 평균 : %d \n", sum/10);

    return 0;
}