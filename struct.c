/* 구조체 포인터 */
#include <stdio.h>

struct test {
    int a, b;
};

int main() {
    struct test st;
    struct test *ptr;

    ptr = &st;

    // *ptr.a = 1; //에러
    (*ptr).a = 1; //st.a = 1 과 동일
    (*ptr).b = 2; //st.b = 2 과 동일
    ptr->a = 3;
    ptr->b = 4;

    printf("st의 a 멤버 : %d \n", st.a);
    printf("st의 b 멤버 : %d \n", st.b);

    return 0;
} 