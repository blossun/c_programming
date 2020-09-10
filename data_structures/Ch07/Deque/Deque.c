#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque *pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdep)
{
	return (pdep->head == NULL) ? TRUE : FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)
{
	Node *pnewNode = (Node *)malloc(sizeof(Node));
	pnewNode->data = data;

	if (DQIsEmpty(pdeq))
	{
		pnewNode->next = NULL;
		pdeq->tail = pnewNode;
	}
	else
	{
		pnewNode->next = pdeq->head;
		pdeq->head->prev = pnewNode;
	}

	pnewNode->prev = NULL;
	pdeq->head = pnewNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
	Node *pnewNode = (Node *)malloc(sizeof(Node));
	pnewNode->data = data;
	pnewNode->next = NULL;

	if (DQIsEmpty(pdeq))
	{
		pnewNode->prev = NULL;
		pdeq->head = pnewNode;
	}
	else
	{
		pnewNode->prev = pdeq->tail;
		pdeq->tail->next = pnewNode;
	}
	pdeq->tail = pnewNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
	Node *rnode = pdeq->head;
	Data retData = rnode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!!\n");
		exit(-1);
	}
	pdeq->head = rnode->next;
	free(rnode);

	// 마지막 데이터를 지웠을 경우에 대한 처리 필요
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return retData;
}

Data DQRemoveLast(Deque *pdeq)
{
	Node *rnode = pdeq->tail;
	Data retData = rnode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!!\n");
		exit(-1);
	}
	pdeq->tail = rnode->prev;
	free(rnode);

	// 마지막 데이터를 지운 경우
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return retData;
}

Data DQPeekFirst(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!!\n");
		exit(-1);
	}

	return pdeq->head->data;
}

Data DQPeekLast(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!!\n");
		exit(-1);
	}

	return pdeq->tail->data;
}
