#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

void StackInit(Stack * pstack)
{
	// CList 생성해서 초기화
	List *list = (List *)malloc(sizeof(List));
	pstack->list = list;
	ListInit(pstack->list);
}

int SIsEmpty(Stack * pstack)
{
	return pstack->list->numOfData == 0 ? TRUE : FALSE;
}

void SPush(Stack * pstack, Data data)
{
	LInsertFront(pstack->list, data);
}

Data SPop(Stack * pstack)
{
	Data data;
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	LFirst(pstack->list, &data);
	LRemove(pstack->list);
	return data;
}

Data SPeek(Stack * pstack)
{
	Data data;
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	LFirst(pstack->list, &data);
	return data;
}
