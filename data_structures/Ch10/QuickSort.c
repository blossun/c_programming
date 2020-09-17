#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽 (중간값이 선택되는 것이 좋다.)

	int low = left+1;
	int high = right;

	while(low <= high)    // 교차되지 않을 때까지 반복
	{
		/* // 주의!! 이렇게 하면 동일한 값(pivot == arr[low])으로 이루어진 경우 while을 벗어나지 못해 버그 발생함!!
		while(pivot > arr[low])
			low++;

		while(pivot < arr[high])
			high--;
		*/

		// 피벗보다 큰 값을 찾는 과정
		// low <= right 는 배열의 정렬 범위를 넘어서지 않도록 하기위한 경계검사 코드
		while(pivot >= arr[low] && low <= right)
			low++;	// low를 오른쪽으로 이동

		// 피벗보다 작은 값을 찾는 과정
		while(pivot <= arr[high] && high >= (left+1))
			high--;	// high를 왼쪽으로 이동


		if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 값을 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환 => pivot 값이 제위치를 찾음
	return high;    // 옮겨진 피벗의 위치정보 반환(제자리를 찾은 피벗의 인덱스 값)
}

void QuickSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서
		QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
	}
}

int main(void)
{
	// int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	// int arr[3] = {3, 3, 3};
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	printf("main!!\n");

	int len = sizeof(arr) / sizeof(int);
	int i;

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
