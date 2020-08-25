#include <stdio.h>

int	factorial(int num)
{
	if (num == 0)
	{
		return (1);
	}
	return num * factorial(num - 1);
}


int	main(void)
{
	int num;

	num = 0;
	printf("%d! -> %d\n", num, factorial(num));

	num = 4;
	printf("%d! -> %d\n", num, factorial(num));

	num = 5;
	printf("%d! -> %d\n", num, factorial(num));

	num = 7;
	printf("%d! -> %d\n", num, factorial(num));
}
