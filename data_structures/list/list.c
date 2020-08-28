#include <stdio.h>
#include "ArrayList_ssun.h"

int main(void)
{
	//문제 03-1 (p85)
	List list;
	int data;
	int sum;

	//1. 리스트 생성 및 초기화, 1~9 값을 리스트에 저장
	ListInit(&list);
	for (data = 0; data < 10; data++)
	{
		LInsert(&list, data);
	}
	//2. 리스트에 저장된 값을 순차적으로 참조, 그 합을 출력
	sum = 0;
	data = 0;
	if (LFirst(&list, &data)) //data에 search한 값이 저장됨
	{
		sum += data;
		while (LNext(&list, &data)) //값이 존재하는 동안 반복
		{
			sum += data;
		}
	}
	printf("total sum : %d\n", sum);
	//3. 리스트에 저장된 값중 2와 3의 배수값들을 삭제
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
		{
			LRemove(&list); //어떤값을 지울지는 안넘김???
			//LRemove 함수가 호출되면, 바로 직전에 LFirst(), LNext()로 참조된 데이터가 삭제 된다.
			while (LNext(&list, &data))
			{
				if (data % 2 == 0 || data % 3 == 0)
					LRemove(&list);
			}
		}
	}
	//4. 리스트에 저장된 데이터를 순서대로 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
}
