#include <stdio.h>
#include "BinaryTree3.h"

// LL 회전
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode와 cNode가 LL회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// 실제 LL회전을 담당하는 2줄
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode)); // 1. PN의 왼쪽 자식 = CN의 오른쪽 자식
	ChangeRightSubTree(cNode, pNode); // 2. CN의 오른쪽 자식 = PN

	// LL 회전으로 인해서 변경된 루트 노드의 주소 값 반환
	return cNode;
}

// RR 회전
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 한다.
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// 실제 RR회전을 담당하는 2줄
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode)); // 1. PN의 오른쪽 자식 = CN의 왼쪽 자식
	ChangeLeftSubTree(cNode, pNode); //2. CN의 왼쪽 자식 = PN
	// RR 회전으로 인해서 변경된 루트 노드의 주소 값 반환
	return cNode;
}

// RL 회전
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));   // 부분적 LL 회전
	// 부분 LL 회전의 결과로 받아온 루트 노드를 pNode의 오른쪽 자식으로 다시 연결
	return RotateRR(pNode);     // RR 회전
}

// LR 회전
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));   // 부분적 RR 회전
	// 부분 RR 회전의 결과로 받아온 루트 노드를 pNode의 왼쪽 자식으로 다시 연결
	return RotateLL(pNode);     // LL 회전
}

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst)
{
	int leftH;		// left height
	int rightH;		// right height

	if(bst == NULL)
		return 0;

	// 왼쪽 서브 트리 높이 계산
	leftH = GetHeight(GetLeftSubTree(bst));

	// 오른쪽 서브 트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));

	// 큰 값의 높이를 반환
	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// 두 서브 트리의 '높이의 차(균형 인수)'를 반환
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;    // left sub tree height
	int rsh;    // right sub tree height

	if(bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst)); // 왼쪽 서브 트리의 높이
	rsh = GetHeight(GetRightSubTree(bst)); // 오른쪽 서브 트리의 높이

	return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot); // 균형 인수 계산

	// 균형 인수가 +2 이상이면 LL 상태 또는 LR 상태이다.
	if(hDiff > 1)
	{
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) // LL 상태라면,
			*pRoot = RotateLL(*pRoot);	// LL 회전 진행
		else							// LR 상태라면,
			*pRoot = RotateLR(*pRoot);	// LR 회전 진행
	}

	// 균형 인수가 -2 이하이면 RR 상태 또는 RL 상태이다.
	if(hDiff < -1)
	{
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0) // RR
			*pRoot = RotateRR(*pRoot);
	else								// RL
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot; // 회전 과정에서 루트 노드가 변경될 수 있으므로 변경된 루트 노드 주소 반환
}
