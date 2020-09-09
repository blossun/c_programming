#include <stdio.h>
#include "CLLBaseStack.h"

int main(void)
{
	// Stack 생성
	printf("[create] ==============>");
	Stack stack;
	StackInit(&stack);

	// 데이터 저장
	printf("[insert] ==============>");
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	// 모든 데이터 출력
	printf("[pop] ==============>");
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
	return 0;
}
