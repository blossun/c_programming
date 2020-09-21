#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
	int s;

	// if(first > last) // 위 조건은 탐색 타겟이 탐색 범위를 벗어날 수 있음
	// 	return -1;    // -1 반환은 탐색의 실패를 의미

	if(ar[first]>target || ar[last]<target)
		return -1;

	// 이진 탐색과의 차이
	// 보간 탐색의 탐색위치를 결정하는 공식
	s = ((double)(target-ar[first]) / (ar[last]-ar[first]) *
			(last-first)) + first;

	if(ar[s] == target)
		return s;    // 탐색된 타겟의 인덱스 값 반환
	else if(target < ar[s])
		return ISearch(ar, first, s-1, target);
	else
		return ISearch(ar, s+1, last, target);
}


int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	return 0;
}


/*
int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	return 0;
}

*/
