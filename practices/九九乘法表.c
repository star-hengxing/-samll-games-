#include<stdio.h>
int main()
{
	int x, y;
	for (x = 1; x <= 9; x++)
	{
		for (y = 1; y <= x; y++)
		{
			printf("%dx%d=%d ", y, x, x * y);
		}
		printf("\n");
	}
	return 0;
}