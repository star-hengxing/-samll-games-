#include<stdio.h>
#pragma warning(disable:4996)
#define max(x,y)(x>y?x:y)

int main()
{
	int a, b, c;
	puts("������������:");
	scanf("%d%d%d", &a, &b, &c);
	printf("�����������ֵΪ:%d\n",max(max(a, b), c));
	return 0;
}