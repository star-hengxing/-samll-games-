#include<stdio.h>
#pragma warning(disable:4996)
#define max(x,y)(x>y?x:y)

int main()
{
	int a, b, c;
	puts("请输入三个数:");
	scanf("%d%d%d", &a, &b, &c);
	printf("三个数中最大值为:%d\n",max(max(a, b), c));
	return 0;
}