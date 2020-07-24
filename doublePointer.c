/* 포인터가 가리키는 변수를 서로 변경 */
#include <stdio.h>

void pswqp(int **ppa, int **ppb);

int main()
{
    int a, b;
    int *pa, *pb;
    pa = &a;
    pb = &b;

    printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);
    printf("pa 의 주소값 : %p \n \n", &pa);
    printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);
    printf("pb 의 주소값 : %p \n", &pb);

    printf("----------swqp 호출 ------------\n");
    pswqp(&pa, &pb);
    printf("----------swqp 종료 ------------\n");

    printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);
    printf("pa 의 주소값 : %p \n \n", &pa);
    printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);
    printf("pb 의 주소값 : %p \n", &pb);

    return 0;
}

void pswqp(int **ppa, int **ppb) {
    int *temp = *ppa;

    printf("ppa가 가리키는 변수의 주소값 : %p \n", ppa);
    printf("ppb가 가리키는 변수의 주소값 : %p \n", ppb);

    *ppa = *ppb;
    *ppb = temp;

}