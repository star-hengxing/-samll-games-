#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>

void gotoxy(int x, int y) //将光标调整到(x,y)的位置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;	SetConsoleCursorPosition(handle, pos);
}
int main()
{
	int m=0;
    system("color f0");
    FILE *fp=NULL;
    char save[254000];
    fp=fopen("C:/Users/Administrator/Desktop/恒星/立方体.txt","r");
    if (!fp)
	{
		puts("文件打开失败!\n");
		exit(1);
	}
	fread(save,1,254000,fp);
	while(1)
	{
		if(m<100)
		{
			m++;
		}
		else if(m>200)
		{
			m--;
		}
		gotoxy(m,1);
		printf("%s",save);
	}
}