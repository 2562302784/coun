#include<stdio.h>
int main()
{
	char str[]="1+2+2+1+2+5+4-1-3+4-8";
	int a,i;
	int c=str[0]-'0';
	for(i=1;i<20;i++)
	{
		if(str[i]=='+')
		{
			a=str[i+1]-'0';
			c=c+a;
			i++;
		}
		else if(str[i]=='-')
		{
			a=str[i+1]-'0';
			c=c-a;
			i++;
		}
	}
	printf("%d\n",c);
	return 0;
}