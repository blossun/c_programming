/* 문자열 */
#include <stdio.h>

int main() {
  char str[] = "hello";
  char *pstr = "goodbye";

  str[1] = 'a';
//   pstr[1] = 'a'; //디버깅하면 여기서 에러나는 것 확인가능. 리터럴값을 수정하려고 하기 때문

  return 0;
}