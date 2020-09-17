#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i=1; i<n; i++) // 정렬대상은 1부터 시작해서 바로 앞 index와 비교
	{
		insData = arr[i];   // 정렬대상을 insData에 저장

		for(j=i-1; j>=0 ; j--) // 바로 앞 index부터 0번 인덱스까지 비교
		{
			if(arr[j] > insData) /* 비교 연산 */
				arr[j+1] = arr[j];    // 비교대상 한 칸 오른쪽으로 밀기
			else	// 비교대상의 값이 앞의 정렬된 값보다 크면 그 위치가 제자리
				break;   // 삽입위치를 찾으면 탈출
		}

		arr[j+1] = insData;  // 찾은 위치에 정렬대상 삽입 //데이터 이동의 핵심연산!!
	}
}


int main(void)
{
	int arr[5] = {5, 3, 2, 4, 1};
	int i;

	InserSort(arr, sizeof(arr)/sizeof(int));

	for(i=0; i<5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
