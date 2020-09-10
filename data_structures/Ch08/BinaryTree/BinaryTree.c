#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode *newBTreeNode = (BTreeNode *)malloc(sizeof(BTreeNode));
	newBTreeNode->left = NULL;
	newBTreeNode->right = NULL;
	return newBTreeNode;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->left != NULL) //기존에 노드가 있다면 메모리 해제해줘야 함
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->right != NULL)
		free(main->right);

	main->right = sub;
}

// 이진트리 순회 추가
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL) // 공집합 노드인지 확인해서 공집합 노드면 재귀 탈출!!
		return ;

	InorderTraverse(bt->left, action); // 1단계 : 왼쪽 서브 트리 순회
	action(bt->data); // 2단계 : 루트노드 방문 -> action 실행
	InorderTraverse(bt->right, action); // 3단계 : 오른쪽 서브 트리 순회
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return ;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return ;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}
