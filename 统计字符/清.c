
#include<stdio.h>
main()
{
	char a[100],word[30];
	int i=0,j,m=0,n=0,count=0,sum=0;
	printf("输入一句英文\n");
	while((a[i] = getchar()) != '\n')
	{
	m++;
	i++;
	}
	i=0;
	printf("输入要查找的单词\n");
	while((word[i] = getchar()) != '\n')
	{
	n++;
	i++;
	}
	for (i = 0; i < na; i++)
	{   
		count = 0;
		if(a[i] == word[0])
		{
			for(j=0;j<n;j++)
		{
            if(a[i+j] == word[j])
			{
                count++;
            }
        }
        if(count == n)sum++;
		}
	}
	printf("你查找的单词的个数:%d",sum);
}