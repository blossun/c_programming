#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{
	List list;
	Data data;
	ListInit(&list);

	//데이터 8개 추가
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	//저장된 데이터 조회
	if (LFirst(&list, &data))
	{
		printf("Data : %d\n", data);

		while (LNext(&list, &data))
		{
			printf("Data : %d\n", data);
		}
	}

	//2의 배수 전부 삭제
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
				LRemove(&list);
		}
	}


	//저장된 데이터 조회
	if (LFirst(&list, &data))
	{
		printf("Data : %d\n", data);

		while (LNext(&list, &data))
		{
			printf("Data : %d\n", data);
		}
	}

}
