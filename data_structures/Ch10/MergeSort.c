#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

	// 병합한 결과를 담을 배열 sortArr의 동적할당
	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	// 병합할 두 영역의 데이터들을 비교하여, 정렬 순서대로 soartArr에 하나씩 옮겨 담는다.
	// mid를 기준으로 배열을 두 영역으로 나누어서 각 영역의 앞에서 부터 서로 비교해나간다.
	while(fIdx<=mid && rIdx<=right)
	{
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if(fIdx > mid) // 배열의 앞부분이 모두 sortArr에 옮겨졌다면
	{
		// 배열의 뒷부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
		for(i=rIdx; i<=right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else // 배열의 뒷부분이 모두 sortArr에 옮겨졌다면
	{
		// 배열의 앞부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
		for(i=fIdx; i<=mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right) // left가 작다는 것은 더 나눌 수 있다는 의미
	{
		// 중간 지점
		mid = (left+right) / 2;

		// 둘로 나눠서 각각을 정렬
		MergeSort(arr, left, mid); // left ~ mid에 위치한 데이터 정렬
		MergeSort(arr, mid+1, right); // mid+1 ~ right에 위치한 데이터 정렬

		// 정렬된 두 배열을 병합
		// 배열 arr의 left~mid까지, mid+1~right까지 각각 정렬되었으니, 이를 하나의 정렬된 상태로 묶어서 배열 arr에 저장해라
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int i;

	// 배열 arr의 전체 영역 정렬
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
