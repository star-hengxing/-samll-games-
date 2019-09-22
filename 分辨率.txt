#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("请输入你的分辨率比例:\n");
	scanf_s("%d:%d",&a,&b);
	printf("请输入你的分辨率长:\n");
	scanf_s("%d",&c);
	d=c/a*b;
	printf("你的分辨率为%dx%d\n",c,d);
	return 0;
}