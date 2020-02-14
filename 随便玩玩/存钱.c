#include<stdio.h>
int main(void)
{
	int x, y, z;
	printf("请输入你的金额:");
	scanf_s("%d", &x);
	printf("请输入你的存款年数:");
	scanf_s("%d", &y);
	z = x * y * 365;
	printf("如果你每天存%d元，那么%d年后，你将会得到%d元\n", x, y, z);
	return 0;
}