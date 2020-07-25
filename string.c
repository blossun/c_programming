/* 구조체 예제 2 */
#include <stdio.h>

char copy_str(char *dest, char *src);
struct Books {
    /* 책이름 */
    char name[30];
    /* 작가 */
    char auth[30];
    /* 출판사 */
    char publ[30];
    /* 대여 여부 */
    int borrowed;
    // int borrowed=0; //에러. 구조체에서 변수 초기화 불가능
};

int main() {
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K Rooling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;

    printf("책 이름 : %s \n", Harry_Potter.name);
    printf("저자 : %s \n", Harry_Potter.auth);
    printf("출판사 : %s \n", Harry_Potter.publ);

  return 0;
}

char copy_str(char *dest, char *src) {
    while(*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}