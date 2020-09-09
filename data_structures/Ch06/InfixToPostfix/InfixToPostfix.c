#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 연산자의 우선순위 정보 반환
// 값이 클수록 높은 우선순위
int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5; // 가장 높은 우선순위
	case '+':
	case '-':
		return 3;
	case '(':
		return 1; // 가장 낮은 우선순위
	}

	return -1;   // 등록되지 않은 연산자
}

// 두 연산자의 우선순위 비교
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if(op1Prec > op2Prec) // op1 우선순위가 더 높은 경우
		return 1;
	else if(op1Prec < op2Prec) // op2 우선순위가 더 높은 경우
		return -1;
	else
		return 0;	//op1과 op2의 우선순위가 같은 경우
}

// 전위 -> 후위 표기법 수식으로 변환
void ConvToRPNExp(char exp[])
{
	Stack stack; // 연산자를 담을 스택(쟁반)
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1); // 변환된 수식을 담을 공간 생성

	int i, idx=0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen+1); // 할당된 배열을 0으로 초기화
	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		tok = exp[i]; // exp로 전달된 수식을 한 문자씩 tok에 저장
		if(isdigit(tok)) // tok에 저장된 문자가 숫자인지 확인
		{
			convExp[idx++] = tok; // 순자인 경우, dst에 바로 저장
		}
		else
		{
			switch(tok) // 연산자인 경우
			{
			case '(':
				SPush(&stack, tok); // 스택에 쌓는다.
				break;

			case ')': // ( 연산자를 만날 때 까지 반복해서 값을 꺼내서 dst에 담는다.
				while(1)
				{
					popOp = SPop(&stack);
					if(popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
			 	//스택에 더 높은 우선순위 연산자가 있으면, 스택에서 연산자를 꺼내서 dst에 저장
				while(!SIsEmpty(&stack) &&
						WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			}
		}
	}

	while(!SIsEmpty(&stack)) // 스택에 남아있는 모든 연산자를
		convExp[idx++] = SPop(&stack); // dst(배열 convExp)에 저장

	strcpy(exp, convExp); //convExp내용(변환된 수식)을 exp로 복사
	free(convExp); //convExp 메모리 해제
}
