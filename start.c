/* switch 문자 비교 */
// 컴퓨터는 문자를 모두 숫자로 처리한 뒤, 우리에게 보여줄 때 에만 문자로 보여주는 것
#include <stdio.h>
int main() {
  char input;

  printf("(소문자) 알파벳 읽기\n");
  printf("알파벳 : ");

  scanf("%c", &input);

  switch (input) {
    case 97: //case 'a': 와 같다.
      printf("에이 \n");
      break;

    case 'b':
      printf("비 \n");
      break;

    case 'c':
      printf("씨 \n");
      break;

    default:
      printf("죄송해요.. 머리가 나빠서 못 읽어요  \n");
      break;
  }

  return 0;
}