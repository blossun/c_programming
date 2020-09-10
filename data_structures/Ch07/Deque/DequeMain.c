#include <stdio.h>
#include "Deque.h"

int main(void)
{
	Data data;
	//Deque 생성 및 초기화
	Deque deque;
	DequeInit(&deque);

	// 데이터 앞에서, 뒤에서 저장
	DQAddFirst(&deque, 3);
	DQAddFirst(&deque, 2);
	DQAddFirst(&deque, 1);
	DQAddLast(&deque, 4);
	DQAddLast(&deque, 5);
	DQAddLast(&deque, 6);

	// 앞에서 추출
	while (!DQIsEmpty(&deque))
		printf("%d ", DQRemoveFirst(&deque));

	printf("\n");

	// 데이터 앞에서, 뒤에서 저장
	DQAddFirst(&deque, 3);
	DQAddFirst(&deque, 2);
	DQAddFirst(&deque, 1);
	DQAddLast(&deque, 4);
	DQAddLast(&deque, 5);
	DQAddLast(&deque, 6);

	// 뒤에서 추출
	while (!DQIsEmpty(&deque))
		printf("%d ", DQRemoveLast(&deque));

	return 0;
}
