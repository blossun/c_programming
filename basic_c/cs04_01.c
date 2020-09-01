/*
1. 미션 제목
숫자 애너그램 찾기

‘애너그램’이란 문자를 재배열하여 다른 뜻을 가진 단어로 바꾸는 것을 말합니다

예)
입력값: 12345, 54321 -> 출력값: True
입력값: 14258, 25431 -> 출력값: False
입력값: 11132, 21131 -> 출력값: True

*/
#include <stdio.h>

void	sort_array(int nums[], int size);
void	print_array(int *array, int size);
int		is_anagram(int nums1[], int nums2[], int size);

int		main(void)
{
	// int	nums1[5] = {1, 4, 2, 5, 8};
	// int	nums2[5] = {2, 5, 4, 3, 1};
	int	nums1[5] = {1, 1, 1, 3, 2};
	int	nums2[5] = {2, 1, 1, 3, 1};
	int nums1_size = (sizeof(nums1) / sizeof(int));
	int nums2_size = (sizeof(nums2) / sizeof(int));

	printf("===== befor sort =====\n");
	print_array(nums1, nums1_size);
	print_array(nums2, nums2_size);

	sort_array(nums1, nums1_size);
	sort_array(nums2, nums2_size);

	printf("===== after sort =====\n");
	print_array(nums1, nums1_size);
	print_array(nums2, nums2_size);

	if (is_anagram(nums1, nums2, nums1_size) == 1)
	{
		printf("is anagram ? TRUE");
	} else
	{
		printf("is anagram ? FALSE");
	}


}

int		is_anagram(int nums1[], int nums2[], int size)
{
	int is_anagram = 1;

	for (int i = 0; i < size; i++)
	{
		if (nums1[i] != nums2[i])
		{
			is_anagram = 2;
		}
	}
	return is_anagram;
}

void	sort_array(int nums[], int size)
{
	int min_index;
	int min_value;
	int current_index;
	int index;

	current_index = 0;
	while (current_index < size)
	{
		min_value = nums[current_index];
		index = current_index;
		min_index = index;
		while(index < size)
		{
			if (nums[index] < min_value)
			{
				min_index = index;
				min_value = nums[index];
			}
			index++;
		}
		nums[min_index] = nums[current_index];
		nums[current_index] = min_value;
		current_index++;
	}
}

void	print_array(int *array, int size)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
