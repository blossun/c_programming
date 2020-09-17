#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1; // 오름차순 정렬
}

void HeapSort(int arr[], int size, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// 정렬대상을 가지고 힙을 구성
	for (i = 0; i < size; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성
	for (i = 0; i < size; i++)
		arr[i] = HDelete(&heap);
}

int main(void)
{
	int arr[4] = {3, 4, 2, 1};
	int i;

	HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
