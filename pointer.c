/* 포인터의 포인터 */
#include <stdio.h>
int main() {
    int a;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    a = 3;

    printf("a : %d // *pa : %d // **pa : %d \n", a, *pa, **ppa);
    printf("&a : %p // pa : %p // *ppa : %p \n", &a, pa, *ppa);
    printf("&a : %p // &*pa : %p // &**pa : %p \n", &a, &*pa, &**ppa); //위와 동일 &와 *는 한쌍씩 상쇄된다.
    printf("&pa : %p // ppa : %p \n", &pa, ppa);

    return 0;
}