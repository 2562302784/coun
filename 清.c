#include<stdio.h>                                                             
#include<string.h>
int n,i,pro,nol,m,s,j,c;
int pro_num[1000];
char str[1000][20];
int nol_num[1000],a[1000];
int main(void)
{
	printf("请输入要录入考生信息的人数：");
        scanf("%d",&n);
        for(i=0;i<n;i++)
		{
			printf("输入考生准考证号、试机座位号、考生座位号分别用空格隔开：");
			scanf("%s %d %d",str[i],&pro,&nol);
            pro_num[i]=pro;
            nol_num[i]=nol;
		}
		printf("请输入需要查询的人数：");
        scanf("%d",&m);
        for(i=0;i<m;i++)
		{
			printf("输入试机座位号:");
			scanf("%d",&pro);
			a[i]=pro;
        }
        j=0;
        while(j<m)
		{
                for(i=0;i<n;i++)
				{
                        if(a[j]==pro_num[i])
						{		
							printf("准考证号为：");
							for(c=0;c<14;c++)
							{
								printf("%c",str[i][c]);
							}
                                printf(" 考试座位号为：%d\n",nol_num[i]);
                                j++;
                               break;
                        }
                }
 
        }
        return 0;
}