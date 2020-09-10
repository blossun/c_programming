#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL) // 공집합 노드인지 확인해서 공집합 노드면 재귀 탈출!!
		return ;

	InorderTraverse(bt->left); // 1단계 : 왼쪽 서브 트리 순회
	printf("%d ", bt->data); // 2단계 : 루트노드 방문 -> 루트 노드 데이터 출력
	InorderTraverse(bt->right); // 3단계 : 오른쪽 서브 트리 순회
}

void PreorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return ;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return ;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d ", bt->data);
}


int main(void)
{
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt1, bt3);

	// 트리 노드 순회
	InorderTraverse(bt1); printf("\n");
	PreorderTraverse(bt1); printf("\n");
	PostorderTraverse(bt1);

	return 0;
}
