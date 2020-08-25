#include <stdio.h>
// 이동횟수는 어떻게 카운트 ?? 전역변수로?

void hanoi(int n, char from, char by, char to)
{
	if (n == 1) //탈출 조건
	{
		printf("%d : %c -> %c\n", n, from, to);
		return ;
	}
	//1단계 - (n - 1)개 원반을 A에서 (C를 거쳐) B로 이동
	hanoi(n - 1, from, to, by);
	//2단계 - n 원반(맨 아래에 있는 가장 큰 원반)을 A에서 C로 이동
	printf("%d : %c -> %c\n", n, from, to);
	//3단계 - 옮겨뒀던 (n - 1)개의 원반을 B에서 (A를 거쳐) C로 이동
	hanoi(n - 1, by, from, to);
}

int main(void)
{
	int	n;

	n = 3;
	hanoi(n, 'A', 'B', 'C'); //A에서 (B를 거쳐) C로 이동
}
