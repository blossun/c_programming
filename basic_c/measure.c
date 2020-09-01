#include <stdio.h>
#include <stdlib.h> //qsort

int *divisor;

int
compare(const void * a, const void * b) //어떠한 자료형도 가져올 수 있도록 void 포인터로 받는다. const : 상수로 받아오도록해서 compare함수 내에서는 값을 변경하지 못하도록 한다.
{
    return (*(int*)a - *(int*)b);//정렬할 배열의 자료형으로 역참조해서 값을 가져옴
}

int
main()
{
    int N;
    scanf("%d", &N);

    divisor = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        divisor[i] = tmp;
    }

    qsort(divisor, N, sizeof(int), compare); //퀵 정렬 : 정렬할 배열(메모리 주소), 요소 개수, 요소 크기, 비교 함수

    int answer = divisor[0] * divisor[N-1]; //N은 약수의 처음 주어진 숫자와 마지막 숫자를 곱한 값
    printf("%d\n", answer);

    return 0;
}
