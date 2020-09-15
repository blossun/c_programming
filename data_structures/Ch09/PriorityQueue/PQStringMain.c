#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * str1, char * str2) // 문자열의 길이가 짧을 수록 높은 우선순위
{
	return strlen(str2) - strlen(str1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);
	PEnqueue(&pq, "Good morning");
	PEnqueue(&pq, "Hi Hello");
	PEnqueue(&pq, "Priority Queue haha");
	PEnqueue(&pq, "so good");
	PEnqueue(&pq, "soo bad");

	while(!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
