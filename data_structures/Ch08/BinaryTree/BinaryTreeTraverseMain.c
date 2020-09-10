#include <stdio.h>
#include "BinaryTree.h"

void action(BTData data)
{
	printf("%d ", data);
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
	InorderTraverse(bt1, &action); printf("\n");
	PreorderTraverse(bt1, &action); printf("\n");
	PostorderTraverse(bt1, &action);

	return 0;
}
