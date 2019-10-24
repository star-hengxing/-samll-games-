#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#pragma warning(disable:4996)

void secretpassword(char secret[])
{
	int i = 0;
	unsigned char x;
	while ((x = getch()) != '\r')
	{
		if (x != '\b' && i >= 0 && i < 20)
		{
			secret[i] = x;
			i++;
			printf("*");
		}
		else if (x == '\b' && i > 0)
		{
			i--;
			printf("\b \b");
		}
	}
	printf("\n");
	secret[i] = '\0';
}
int main()
{
	printf("密码长度为0-20字母数字(分大小写)\n请设置你的密码:");
	char password[20];
	secretpassword(password);
	printf("\n你的密码是:%s", password);
	return 0;
}

