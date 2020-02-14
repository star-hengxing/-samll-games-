#include<stdio.h>
int f(int n){
        if(n< 4){
            return n;
        }
        else{
            return f(n-1)+f(n-3);
        }
    }
int main()
{
    int n;
    int f(int n);
    while(scanf("%d", &n) !=EOF&&n>0)
    {
        printf("%d\n",f(n)) ;
    }    
}