#include<stdio.h>                                                             
#include<string.h>
int n,i,pro,nol,m,s,j,c;
int pro_num[1000];
char str[1000][20];
int nol_num[1000],a[1000];
int main(void)
{
	printf("������Ҫ¼�뿼����Ϣ��������");
        scanf("%d",&n);
        for(i=0;i<n;i++)
		{
			printf("���뿼��׼��֤�š��Ի���λ�š�������λ�ŷֱ��ÿո������");
			scanf("%s %d %d",str[i],&pro,&nol);
            pro_num[i]=pro;
            nol_num[i]=nol;
		}
		printf("��������Ҫ��ѯ��������");
        scanf("%d",&m);
        for(i=0;i<m;i++)
		{
			printf("�����Ի���λ��:");
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
							printf("׼��֤��Ϊ��");
							for(c=0;c<14;c++)
							{
								printf("%c",str[i][c]);
							}
                                printf(" ������λ��Ϊ��%d\n",nol_num[i]);
                                j++;
                               break;
                        }
                }
 
        }
        return 0;
}