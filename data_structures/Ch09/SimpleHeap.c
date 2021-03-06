#include "SimpleHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc; //우선순위 비교에 사용되는 함수의 등록
}

int HIsEmpty(Heap * ph) // 힙이 비었는지 확인
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) //부모 노드의 인덱스 값 반환
{
	return idx/2;
}

int GetLChildIDX(int idx) //왼쪽 자식 노드의 인덱스 값 반환
{
	return idx*2;
}

int GetRChildIDX(int idx) //오른쪽 자식 노드의 인덱스 값 반환
{
	return GetLChildIDX(idx)+1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)    // 자식 노드가 존재하지 않는 경우
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)    // 자식 노드가 왼쪽 자식 노드 하나만 존재하는 경우
		return GetLChildIDX(idx);

	else   // 자식 노드가 둘 다 존재하는 경우
	{
		// 오른쪽 자식 노드의 우선순위가 높다면,
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)],
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx); //오른쪽 자식 노드의 인덱스 값 반환
		else //왼쪽 자식 노드의 우선순위가 높다면
			return GetLChildIDX(idx); //왼쪽 자식 노드의 인덱스 값 반환
	}
}

// 힙에 데이터 저장
void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData+1; // 새 노드가 저장될 인덱스 값을 idx에 저장

	// 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
	while(idx != 1)
	{
		// 새 노드와 부모 노드의 우선순위 비교
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) // 새 노드의 우선순위가 높다면
		{
			// 부모 노드를 한 레벨 내림. 실제로 내림
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			// 새 노드를 한 레벨 올림. 실제로 올리지는 않고 인덱스 값만 갱신
			idx = GetParentIDX(idx);
		}
		else // 새 노드의 우선순위가 높지 않다면
			break;
	}

	ph->heapArr[idx] = data; //새 노드를 배열에 저장
	ph->numOfData += 1;
}

// 힙에서 데이터 삭제
HData HDelete(Heap * ph)
{
	HData retData = (ph->heapArr[1]);    // 반환을 위해 삭제할 데이터 저장
	HData lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장

	// parentIdx에 마지막 노드가 저장될 위치정보가 담긴다.
	int parentIdx = 1;    // 루트 노드가 위치해야할 인덱스 값 저장
	int childIdx;

	// 루트노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) //마지막 노드와 우선순위 비교
			break; // 마지막 노드의 우선순위가 높으면 반복문 탈출

		// 루트 노드로 옮겨진 마지막 노드와 우선순위가 높은 자식 노드와의 교환
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // childIdx에 위치한 노드를 부모 노드의 위치로 올림. 실제로 올림
		parentIdx = childIdx; // parentIdx에 위치한 노드를 자식 노드의 위치로 내림. 실제로 내리지 않음
	}

	ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
	ph->numOfData -= 1;
	return retData;
}
