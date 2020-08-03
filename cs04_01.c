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

int		main(void)
{
	int	nums[5] = {1, 4, 2, 5, 8};
	int size = (sizeof(nums) / sizeof(int));

	sort_array(nums, size);

	for (int i = 0; i < 5; i++)
	{
		printf("%d \n", nums[i]);
	}
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
