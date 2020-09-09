#ifndef __CLLBASESTACK_H__
#define __CLLBASESTACK_H__

#include "CLinkedList.h"

#define TURE 1
#define FALSE 0

// 직접 노드 구조를 짜는게 아니라 CLL을 가져다 쓰기...

// head로 CLL의 머리(tail->next)만 알면 될 것 같기도?
typedef struct _clistStack
{
	List *list;
} CListStack;

typedef CListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif
