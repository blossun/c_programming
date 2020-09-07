#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "DLinkedList.h"

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1->xpos < d2->xpos)
		return 0;
	else if (d1->xpos == d2->xpos)
		return d1->ypos <= d2->ypos ? 0 : 1;
	else
		return 1;

}

int main(void)
{
	// List�� ���� �� �ʱ�ȭ  ////////////
	List list;
	Point comp;
	Point *pPoint;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	// 5���� ������ ����  ///////////////
	pPoint = (Point *)malloc(sizeof(Point));
	SetPointPos(pPoint, 3, 2);
	LInsert(&list, pPoint);

	pPoint = (Point *)malloc(sizeof(Point));
	SetPointPos(pPoint, 3, 1);
	LInsert(&list, pPoint);

	pPoint = (Point *)malloc(sizeof(Point));
	SetPointPos(pPoint, 2, 2);
	LInsert(&list, pPoint);

	pPoint = (Point *)malloc(sizeof(Point));
	SetPointPos(pPoint, 2, 1);
	LInsert(&list, pPoint);

	// ����� �������� ��ü ��� ////////////
	printf("전체 데이터 출력: %d \n", LCount(&list));

	if(LFirst(&list, &pPoint))
	{
		ShowPointPos(pPoint);

		while(LNext(&list, &pPoint))
			ShowPointPos(pPoint);
	}
	printf("\n");

	// ���� 22�� �˻��Ͽ� ��� ���� ////////////
	comp.xpos = 2;
	comp.ypos = 0;

	if(LFirst(&list, &pPoint))
	{
		if(PointComp(pPoint, &comp) == 1)
		{
			pPoint = LRemove(&list);
			free(pPoint);
		}

		while(LNext(&list, &pPoint))
		{
			if(PointComp(pPoint, &comp) == 1)
			{
				pPoint = LRemove(&list);
				free(pPoint);
			}
		}
	}

	// ���� �� ����� ������ ��ü ��� ////////////
	printf("삭제 후 전체 데이터 출력: %d \n", LCount(&list));

	if(LFirst(&list, &pPoint))
	{
		ShowPointPos(pPoint);

		while(LNext(&list, &pPoint))
			ShowPointPos(pPoint);
	}
	printf("\n");
	return 0;
}
