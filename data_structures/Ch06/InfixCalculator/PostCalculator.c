#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 후위표기법 수식을 계산하여 결과를 반환
int EvalRPNExp(char exp[])
{
	//피연산자를 담을 스택
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];


		if (isdigit(tok)) // 정수면 숫자로 변환해서 스택에 쌓아 놓음
		{
			SPush(&stack, tok - '0');
		}
		else
		{
			op2 = SPop(&stack); // 먼저 꺼낸 피연산자 (오른쪽)
			op1 = SPop(&stack); // 두 번째 꺼낸 피연산자 (왼쪽)

			// 연산결과는 다시 스택에 넣는다.
			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			default:
				break;
			}
		}
	}
	return SPop(&stack); //최종 결과 반환
}
