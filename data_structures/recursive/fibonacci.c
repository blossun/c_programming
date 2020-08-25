#include <stdio.h>

int	fibo(int num)
{
	if (num == 1)
		return (0);
	if (num == 2)
		return (1);
	return fibo(num - 2) + fibo(num - 1);
}

int main(void)
{
	int index;
	int num;

	index = 1;
	num = 15;
	while (index < num)
	{
		printf("%d ", fibo(index));
		index++;
	}
}
