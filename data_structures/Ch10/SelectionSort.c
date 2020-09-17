#include <stdio.h>

void SelSort(int arr[], int n)
{
	int i, j;
	int minIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		minIdx = i;    // 최소값이 담긴 index
		printf("minIdx : %d \n", minIdx);

		for(j=i+1; j<n; j++)   // 최솟값 탐색
		{
			if(arr[j] < arr[minIdx]) //<-- 선택정렬의 비교 연산
			{
				minIdx = j;
				printf("## minIdx : %d \n", minIdx);
			}
		}

		/* 교환 */
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}


int main(void)
{
	int arr[4] = {3, 4, 2, 1};
	int i;

	printf("[before] =============\n");
		for(i=0; i<4; i++)
		printf("%d ", arr[i]);
	printf("\n");

	SelSort(arr, sizeof(arr)/sizeof(int));

	printf("[after] =============\n");
	for(i=0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
