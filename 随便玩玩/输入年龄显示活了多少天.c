#include<stdio.h>
int main(void)
{
	int age, day;
	printf("请输入你的年龄:");
	scanf_s("%d", &age);
	day = age * 365;
	printf("你现在%d岁，活了%d天\n",age,day);
	return 0;
}
