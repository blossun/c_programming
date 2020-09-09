#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InfixCalculator.h"
#include "InfixToPostfix.h" //for 중위 -> 후위 표현식 변환
#include "PostCalculator.h" // 후위 표현식 계산

// 사용자로 부터 중위 표현법 수식으로 계산식을 입력받아서 결과값을 반환
int EvalInfixExp(char exp[])
{
	int expLen = strlen(exp);
	char *expCopy = (char *)malloc(sizeof(char)*(expLen + 1));
	strcpy(expCopy, exp);

	ConvToRPNExp(expCopy);
	return EvalRPNExp(expCopy);
}
