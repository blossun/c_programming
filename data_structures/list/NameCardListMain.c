#include "ArrayList_ssun.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 1. 총 3명의 전화번호 정보를 리스트에 저장
	List list;
	char *name;
	char *phone;
	NameCard *target;

	name = "조승우";
	phone = "010-1111-222";
	NameCard *card1 = MakeNameCard(name, phone);

	name = "김태리";
	phone = "010-2222-3333";
	NameCard *card2 = MakeNameCard(name, phone);

	name = "하하하";
	phone = "010-3333-4444";
	NameCard *card3 = MakeNameCard(name, phone);

	ListInit(&list);
	LInsert(&list, card1);
	LInsert(&list, card2);
	LInsert(&list, card3);

	// 모든 정보 출력
	if(LFirst(&list, &target))
	{
		ShowNameCardInfo(target);
		while (LNext(&list, &target))
			ShowNameCardInfo(target);
	}

	// 2. 특정 이름을 대상으로 탐색 진행, 그 사람의 정보 출력
	name = "조승우";
	if (LFirst(&list, &target))
	{
		if (NameCompare(target, name) == 0) //같으면 0
			ShowNameCardInfo(target);
		else
		{
			while (LNext(&list, &target))
			{
				if (NameCompare(target, name))
				{
					ShowNameCardInfo(target);
					break;
				}
			}
		}

	}

	// 3. 특정 이름을 대상으로 탐색 진행, 그 사람의 전화번호 정보를 변경
	name = "김태리";
	char *newPhoneNumber = "010-9999-9999";
	if (LFirst(&list, &target))
	{
		if (!NameCompare(target, name))
			ChangePhoneNum(target, newPhoneNumber);
		else
		{
			while (LNext(&list, &target))
			{
				if (!NameCompare(target, name))
				{
					ChangePhoneNum(target, newPhoneNumber);
					break;
				}
			}
		}

	}

	// 4. 특정 이름을 대상으로 탐색 진행, 그 사람의 정보 삭제
	name = "하하하";
	if (LFirst(&list, &target))
	{
		if (!NameCompare(target, name))
			LRemove(&list);
		while (LNext(&list, &target))
		{
			if (!NameCompare(target, name))
			{
				LRemove(&list);
				break;
			}
		}
	}
	// 5. 남아있는 모든 사람의 전화번호 정보를 출력
	if(LFirst(&list, &target))
	{
		ShowNameCardInfo(target);
		while (LNext(&list, &target))
			ShowNameCardInfo(target);
	}
}
