#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

// 양방향 연결리스트
// 더미 노드가 리스트 앞, 뒤에 존재
// 포인터 변수 head와 tail이 리스트의 앞과 뒤를 가리킴

void ListInit(List * plist)
{
	Node *DmyHead = (Node *)malloc(sizeof(Node));
	Node *DmyTail = (Node *)malloc(sizeof(Node));
	plist->head = DmyHead;
	plist->tail = DmyTail;

	DmyHead->prev = NULL;
	DmyHead->next = plist->tail;

	DmyTail->prev = plist->head;
	DmyTail->next = NULL;

	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->tail;
	newNode->prev = plist->tail->prev;
	newNode->prev->next = newNode;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head->next == plist->tail)
		return FALSE;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == plist->tail)
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data data = rpos->data;

	rpos->prev->next = rpos->next;
	rpos->next->prev = rpos->prev;

	// cur 참조를 하나 앞으로 이동
	plist->cur = rpos->prev;
	free(rpos);
	(plist->numOfData)--;
	return data;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
