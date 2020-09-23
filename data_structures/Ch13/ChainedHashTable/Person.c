#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p) // 키 값을 받아오기위해
{
	return p->ssn;
}

void ShowPerInfo(Person * p)
{
	printf("주민번호 : %d \n", p->ssn);
	printf("이름 : %s \n", p->name);
	printf("주소 : %s \n\n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}
