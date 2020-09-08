#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CLinkedList.h"

Employee *WhoIsNightDuty(List *plist, char *name, int day);
void ShowEmployee(Employee *pem);

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화
	List list;
	ListInit(&list);
	Employee *pem;
	int i;

	// 리스트에 5개의 데이터 추가
	pem = (Employee *)malloc(sizeof(Employee));
	strcpy(pem->name, "solar");
	pem->number=3;
	LInsert(&list, pem);

	pem = (Employee *)malloc(sizeof(Employee));
	strcpy(pem->name, "Hololo");
	pem->number=1;
	LInsert(&list, pem);

	pem = (Employee *)malloc(sizeof(Employee));
	strcpy(pem->name, "coco");
	pem->number=2;
	LInsert(&list, pem);

	pem = (Employee *)malloc(sizeof(Employee));
	strcpy(pem->name, "papico");
	pem->number=5;
	LInsert(&list, pem);

	pem = (Employee *)malloc(sizeof(Employee));
	strcpy(pem->name, "choco");
	pem->number=4;
	LInsert(&list, pem);

	// 당직자 확인
	pem = WhoIsNightDuty(&list, "coco", 3);
	printf("expected %s\n", "solar");
	ShowEmployee(pem);

	pem = WhoIsNightDuty(&list, "solar", 8);
	printf("expected %s\n", "papico");
	ShowEmployee(pem);

	return 0;
}

Employee *WhoIsNightDuty(List *plist, char *name, int day)
{
	int i, j, count;
	Employee *duty;

	count = LCount(plist);
	LFirst(plist, &duty);
	if (strcmp(duty->name, name) == 0)
	{
		i = 0;
		while (i < day)
		{
			LNext(plist, &duty);
			printf("duty name : %s\n", duty->name);
			i++;
		}
		return duty;
	}
	j = 0;
	while (j < count - 1)
	{
		LNext(plist, &duty);
		if (strcmp(duty->name, name) == 0)
		{
			i = 0;
			while (i < day)
			{
				LNext(plist, &duty);
				printf("duty name : %s\n", duty->name);
				i++;
			}
			return duty;
		}
	}
	return NULL;
}

void ShowEmployee(Employee *pem)
{
	printf("Employee name : %s\n", pem->name);
	printf("Employee number : %d\n", pem->number);
}
