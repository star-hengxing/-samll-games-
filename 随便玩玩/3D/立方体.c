#include<stdio.h>
#include<Windows.h>
int main()
{
    system("color f0");
    int x = 10;//正方体边长
    int a = 6, b = 8, c = 10;//底，高，斜边
    int m = a, n = a + x - 1;
    int k = a, l = a + x - 1;
    for (int i = 0; i < b + x; i++)
    {
        for (int j = 0; j < a + x; j++)
        {
            if (j > a&& i == 0)
            {
                printf("*");
            }
            else if (i == b - 1 && j < x)
            {
                printf("*");
            }
            else if (i < b && j == m && m >= 0)
            {
                m--;
                printf("*");
            }
            else if (i < b && j == n && n >= x)
            {
                n--;
                printf("*");
            }
            else if (i >= b && j == 0 && i < b + x - 1)
            {
                printf("*");
            }
            else if (i >= b && j == x && i < b + x - 1)
            {
                printf("*");
            }
            else if (i == b + x - 1 && j < x)
            {
                printf("*");
            }
            else if (i < x && (j == a || j == a + x - 1))
            {
                printf("*");
            }
            else if (j > a&& i == x)
            {
                printf("*");
            }
            else if (i > x&& j == k && k > 0)
            {
                k--;
                printf("*");
            }
            else if (i > x&& j == l && l >= x)
            {
                l--;
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
