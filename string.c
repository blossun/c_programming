/* 문자열 입력*/
#include <stdio.h>

int main() {
   char word[30]; //29자 이하의 문자열을 입력받을 수 있는 데이터

   printf("30자 이내의 문자열 입력 : ");
   scanf("%s", word); // &연산자 필요없음. 배열의 이름 자체가 배열을 가리키고 있는 포인터

   printf("문자열 : %s \n", word);

    return 0;
}
