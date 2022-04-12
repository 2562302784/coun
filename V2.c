#include<stdio.h>
int main()
{
	char str[]="2*2/4*1/1*2*3/2";
	int a,i;
	int c=str[0]-'0';
	for(i=1;i<14;i++)
	{
		if(str[i]=='*')
		{
			a=str[i+1]-'0';
			c=c*a;
			i++;
		}
		else if (str[i]=='/')
		{
			a=str[i+1]-'0';
			c=c/a;
			i++;
		}
	}
		printf("%d\n",c);
	return 0;
}