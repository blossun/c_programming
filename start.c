#include <stdio.h>
int main() {
  int a,b;
  float c,d;

  a = 5;
  b = 3;

  c = a / b;
  d = (float)a / b;

  printf("두 수의 비율 : %f %f", c, d); //두 수의 비율 : 1.000000 1.666667

  return 0;
}