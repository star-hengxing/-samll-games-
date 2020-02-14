#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
char s[] = "金木水火土";
int main()
{
	while (1)
	{
		system("cls");
		srand(time(NULL));
		int c = rand() % 5;
		printf("%c%c\n", s[c * 2], s[c * 2 + 1]);
		Sleep(1000);
	}
	return 0;
}
