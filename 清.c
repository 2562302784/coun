#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define ROW 9
#define COL 11
char map[ROW][COL+1]={
        {"*#*********"},
		{"***###*###*"},
		{"###**#****#"},
		{"*#**###**#*"},
		{"***********"},
        {"#####*##*##"},
		{"**#*****#*E"},
		{"***#*###**#"},
		{"*#*********"},
};

void print_map()
{
	for(int i=0;i<ROW;i++)
	{
		puts(map[i]);
	}
}

void show_cursor(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int curX,curY;
int main()
{
	printf("请按迷宫走出去，向上为w向下为s左边a右边d");
	while(1)
	{
		system("cls");
		print_map();
		show_cursor(curX,curY);
		char t=getch();
		if(t=='w')
		{
			if((curY-1)>=0&&(map[curY-1][curX]=='*'||map[curY-1][curX]=='E')) curY--;
		}
		else if(t=='s')
		{
			if((curY+1)<ROW&&(map[curY+1][curX]=='*'||map[curY+1][curX]=='E')) curY++;
		}
		else if(t=='s')
		{
			if((curY+1)<ROW&&(map[curY+1][curX]=='*'||map[curY+1][curX]=='E')) curY++;
			
		}
		else if(t=='a')
		{
			if((curX-1)>=0&&(map[curY][curX-1]=='*'||map[curY][curX-1]=='E')) curX--;
		}
		else if(t='d')
		{
			if((curX+1)<COL&&(map[curY][curX+1]=='*'||map[curY][curX+1]=='E'))curX++;
		}
		if(map[curY][curX]=='E')
		{   
		    printf("恭喜你呀，获得重生了\t");
			break;
		}
	}
	return 0;
}

