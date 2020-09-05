#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL; // 리스트 머리
	Node * tail = NULL; // 리스트 꼬리
	Node * cur = NULL; // 데이터 조회 시 사용

	Node * newNode = NULL;
	int readData;

	/**** 데이터를 입력받는 과정 ****/
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/*** 노드 추가 과정 ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if(head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** 입력받은 데이터의 출력과정 ****/
	printf("입력받은 데이터 전체 출력! \n");
	if(head == NULL)
	{
		printf("저장된 자연수가 없어요! \n");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data);   //첫 번째 데이터 출력

		while(cur->next != NULL)    //두 번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리 해제 과정 ****/
	if(head == NULL)
	{
		return 0;    // 해제할 노드가 없는 경우.
	}
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%d을(를) 삭제 \n", head->data);
		free(delNode);    // 첫 번째 노드 삭제

		while(delNextNode != NULL)    // 두 번째 이후 노드 삭제
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제 \n", delNode->data);
			free(delNode);    // 동적 할당 메모리 해제
		}
	}

	return 0;
}
