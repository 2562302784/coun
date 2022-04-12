#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void moveOperator(char *p)
{
	while(*p!='\0')
	{
		*p=*(p+1);
		p++;
	}
}
void moveOperand(float *p,float *end)
{
	while(p!=end)
	{
		*p=*(p+1);
		p++;
	}
}
int main()
{
	printf("请输入一个式子，包含+ - * /\n");
	char strEXP[100];
	scanf("%s",strEXP);
	char operators[100]={'\0'};
	float operands[100];
	int operatorsIndex=0;
	for(int i=0;i<strlen(strEXP);i++)
	{
		if(isOperator(strEXP[i]))
		{
			operators[operatorsIndex]=strEXP[i];
			operatorsIndex++;
		}
	}
	int operandsIndex=0;
	for(int i=0;i<strlen(strEXP);i++)
	{
		char temp[100]={'\0'};
		int tempIndex=0;
		while(!isOperator(strEXP[i]))
		{
			temp[tempIndex]=strEXP[i];
			i++;
			tempIndex++;
		}
		float floatV = atof(temp);
		operands[operandsIndex++]=floatV;
	}
	char *poperator=operators;
	float *poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='*')
		{
			float leftOperand = *poperand;
			float rightOperand = *(poperand+1);
			float res = leftOperand * rightOperand;
			*poperand = res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else if(*poperator=='/')
		{
			float leftOperand = *poperand;
			float rightOperand = *(poperand+1);
			float res = leftOperand / rightOperand;
			*poperand = res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else
		{
			poperator++;
			poperand++;
		}
	}
	poperator=operators;
	poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='+')
		{
			float leftOperand = *poperand;
			float rightOperand = *(poperand+1);
			float res = leftOperand + rightOperand;
			*poperand = res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else if(*poperator=='-')
		{
			float leftOperand = *poperand;
			float rightOperand = *(poperand+1);
			float res = leftOperand - rightOperand;
			*poperand = res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else
		{
			poperator++;
			poperand++;
		}
	}
	printf("答案为：%0.2f\n",operands[0]);
	return 0;
}