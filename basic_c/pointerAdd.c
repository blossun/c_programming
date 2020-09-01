/* 포인터의 덧셈 */
#include <stdio.h>

int main() {
  int a;
  char b;
  double c;
  int* pa = &a;
  char* pb = &b;
  double* pc = &c;

  printf("int* pa 의 값 : %p \n", pa);
  printf("int* (pa + 1) 의 값 : %p \n", pa + 1);
  printf("char* pb 의 값 : %p \n", pb);
  printf("char* (pb + 1) 의 값 : %p \n", pb + 1);
  printf("double* pc 의 값 : %p \n", pc);
  printf("double* (pc + 1) 의 값 : %p \n", pc + 1);

    return 0;
}