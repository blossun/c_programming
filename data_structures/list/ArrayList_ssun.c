#include <stdio.h>
#include "ArrayList_ssun.h"

void ListInit(List *plist)
{
	plist->numOfData = 0; //list에 저장된 데이터 수 : 0
	plist->curPosition = -1; //현재 아무 위치도 가리키지 않음
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData > LIST_LEN) //저장공간이 가득 찬 경우
	{
		puts("데이터가 가득찼습니다.");
		return ;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	if ((plist -> numOfData) == 0) //참조할 데이터가 없는 경우
		return FALSE;

	plist->curPosition = 0; //참조 위치 초기화. 첫번째 데이터 참조
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->curPosition >= plist->numOfData - 1) //참조위치가 잘못된 경우(ex. 마지막 참조)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List *plist)
{
	// 참조가 이루어진 curPosition의 데이터를 삭제하고, 뒤에 저장된 데이터를 하나씩 앞으로 이동시켜야 한다.
	int rpos = plist->curPosition; //삭제할 데이터의 인덱스 값
	int totalData = plist->numOfData;
	LData temp = plist->arr[rpos];

	while (rpos < totalData - 1)
	{
		plist->arr[rpos] = plist->arr[rpos + 1];
		rpos++;
	}
	(plist->numOfData)--;
	(plist->curPosition)--; //curPosition은 참조가 이루어진 데이터의 인덱스를 담고있어야 하므로 -1 해준다.
	return (temp);
}

int LCount(List *plist)
{
	return (plist->numOfData);
}
