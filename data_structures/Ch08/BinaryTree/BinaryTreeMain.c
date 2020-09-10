#include <stdio.h>
#include "BinaryTree.h"

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

	//bt2 출력
	BTData data = GetData(GetLeftSubTree(bt1));
	printf("%d\n", data);

	//bt4 출력
	BTData data2 = GetData(GetLeftSubTree(GetLeftSubTree(bt1)));
	printf("%d\n", data2);

	return 0;
}
