#include <stdio.h>

int	bsearch(int *arr, int target, int first, int last)
{
	int mid;

	if (first > last)
		return (-1); //탐색 실패 종료
	mid = (first + last) / 2;
	if (arr[mid] == target)
		return (mid);	//탐색된 타겟의 인덱스값 반환
	if (arr[mid] > target)
		last = mid - 1;
	else
		first = mid + 1;
	return bsearch(arr, target, first, last);
}

void	print_result(int target, int result)
{
	printf("find num : %d\n", target);
	if (result == -1)
		printf("탐색 실패\n");
	else
		printf("=> index : %d\n", result);
}

int	main(void)
{
	int arr[] = {1, 2, 3, 5, 6, 7, 8, 10, 12, 13, 14, 15}; //정렬된 상태여야 함
	int	target;
	int	first;
	int	last;

	first = 0;
	last = sizeof(arr) / sizeof(int) - 1;
	target = 8;
	print_result(target, bsearch(arr, target, first, last));

	target = 11;
	print_result(target, bsearch(arr, target, first, last));

	target = 1;
	print_result(target, bsearch(arr, target, first, last));

	target = 15;
	print_result(target, bsearch(arr, target, first, last));
}
