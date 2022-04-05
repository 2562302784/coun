#include <stdio.h>
int main()
{
	char str[]="3+4";
	int a,b,c;
	a=str[0]-'0';
	b=str[2]-'0';
	c=a+b;
	printf("%d\n",c);
	
    return 0;
}