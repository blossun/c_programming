#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// List 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 데이터 저장
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터 전체 출력
	printf("전체 데이터 출력 %d \n", LCount(&list));

	if(LFirst(&list, &data))    // 첫번째 데이터
	{
		printf("%d ", data);

		while(LNext(&list, &data))    // 두번째 이후 데이터
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22를 검색하여 모두 삭제
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);

		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	printf("[test] end of remvoe 22");
	// 삭제 후 남아있는 데이터 전체 출력
	printf("전체 데이터 출력: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
