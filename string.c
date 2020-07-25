/* 구조체 */
#include <stdio.h>

struct Human {
    int age;
    int height;
    int weight;
};

int main() {
    struct Human Holar;

    Holar.age = 99;
    Holar.height = 170;
    Holar.weight = 55;

    printf("Holar에 대한 정보 \n");
    printf("나이 : %d \n", Holar.age);
    printf("키  : %d \n", Holar.height);
    printf("몸무게 : %d \n", Holar.weight);

  return 0;
}