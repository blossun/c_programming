#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		pnode = MakeBTreeNode();

		if(isdigit(exp[i]))		// 피연산자인 경우
		{
			SetData(pnode, exp[i]-'0'); // 문자를 정수로 바꿔서 (스택에 저장)
		}
		else					// 연산자인 경우
		{
			MakeRightSubTree(pnode, SPop(&stack)); // 먼저 꺼낸 피연산자 -> 오른쪽 자식으로 연결
			MakeLeftSubTree(pnode, SPop(&stack)); // 두번째 꺼낸 피연산자 -> 왼쪽 자식으로 연결
			SetData(pnode, exp[i]); // 루트 트리 노드(연산자 노드)의 주소값으로 (스택에 저장)
		}

		SPush(&stack, pnode); // 스택에 저장
	}

	return SPop(&stack); // 최종 완성된 수식 트리의 루트 노드 주소값 반환
}

int EvaluateExpTree(BTreeNode * bt)
{
	int op1, op2;

	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL) // 탈출 조건 - 단말 노드 라면
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt)); //왼쪽 서브 트리 계산한 결과
	op2 = EvaluateExpTree(GetRightSubTree(bt)); //오른쪽 서브 트리 계산한 결과

	switch(GetData(bt)) //연산자를 확인하여 연산을 진행
	{
	case '+':
		return op1+op2;
	case '-':
		return op1-op2;
	case '*':
		return op1*op2;
	case '/':
		return op1/op2;
	}

	return 0;
}

void ShowNodeData(int data) // 노드의 방문 결과를 결정하는 함수구현
{
	if(0<=data && data<=9)  // 피연산자 출력
		printf("%d ", data);
	else					// 연산자 출력
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
