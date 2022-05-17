#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct JPXX
{
	char gjm[30];
	int jps,yps,tps,hj,pm;
}Jpxx;
void swap_int(int *a,int *b)
{
	int t;
	t=*a,*a=*b,*b=t;
}
void swap_str(char *a,char *b){
	char t[30];
	strcpy(t,a),strcpy(a,b),strcpy(b,t);
}
void sort(Jpxx *jpxx,int cnt)
{
	int i,j;
	for(i=0;i<cnt-1;i++)
		for(j=i+1;j<cnt;j++)
		{
			if(jpxx[j].jps>jpxx[i].jps|| 
			jpxx[j].jps==jpxx[i].jps&&jpxx[j].yps>jpxx[i].yps|| 
			jpxx[j].jps==jpxx[i].jps&&jpxx[j].yps==jpxx[i].yps&&jpxx[j].tps>jpxx[i].tps)
			{
				swap_str(jpxx[i].gjm,jpxx[j].gjm);
				swap_int(&jpxx[i].jps,&jpxx[j].jps);
				swap_int(&jpxx[i].yps,&jpxx[j].yps);
				swap_int(&jpxx[i].tps,&jpxx[j].tps);
				swap_int(&jpxx[i].hj,&jpxx[j].hj);
				swap_int(&jpxx[i].pm,&jpxx[j].pm);
			}
		}

}
void show(Jpxx *jpxx,int cnt)
{
	printf("\n%20s%10s%10s%10s%10s%10s\n","国家名","金牌数","银牌数","铜牌数","总计","总排名");
	printf("**************************************************************************\n");
	for(int j=0;j<cnt;j++)
	{
		printf("%20s%10d%10d%10d%10d%10d\n",jpxx[j].gjm,
			jpxx[j].jps,jpxx[j].yps,jpxx[j].tps,jpxx[j].hj,jpxx[j].pm);
	}
	printf("**************************************************************************\n");

}
void save(Jpxx *jpxx,int cnt)
{
	FILE *fp;
	fp=fopen("c:\\data\\olympic.dat","w");
	if(fp==NULL)
	{
		printf("存盘失败！");return;
	}
	for(int j=0;j<cnt;j++)
	{
		fprintf(fp,"%20s%10d%10d%10d%10d%10d\n",jpxx[j].gjm,
			jpxx[j].jps,jpxx[j].yps,jpxx[j].tps,jpxx[j].hj,jpxx[j].pm);
	}
	if(fclose(fp)==0)
		printf("数据保存成功！");
}
void main(){
	Jpxx jpxx[30];
	FILE*fp;
	fp=fopen("C:\\冬奥会奖牌榜.txt","r");
	if(fp==NULL){//(!fp)；(fp==0)；
		printf("文件\"%s\"打开失败！\n","冬奥.txt");
		return;
	}
	else
	{
		printf("文件\"%s\"打开成功！\n","冬奥.txt");
		char bt1[20],bt2[20],bt3[20],bt4[20],bt5[20],bt6[20];
		int i=0;
		fscanf(fp,"%s%s%s%s%s%s",bt1,bt2,bt3,bt4,bt5,bt6);
		while(!feof(fp))//到文件尾部一直循环
		{
			fscanf(fp,"%s%d%d%d%d%d",jpxx[i].gjm,
				&jpxx[i].jps,&jpxx[i].yps,&jpxx[i].tps,&jpxx[i].hj,&jpxx[i].pm);
			i++;
		}
		printf("排序前：\n\n");
		show(jpxx,i);
		sort(jpxx,i);
		printf("排序后：\n\n");
		show(jpxx,i);
		system("pause");
		printf("是否需要存盘？1---Yes；0----NO");
		int j;
		scanf("%d",&j);
		if(j==1)save(jpxx,i);
		fclose(fp);//关闭文件
	}
}

