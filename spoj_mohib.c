#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int x,avg,n;
         scanf("%d%d",&x,&avg);
         n = avg - x;
         int sum = n * (avg + 1);
         sum = sum - (n*(n-1)/2) ;

         printf("%d\n",sum);
    }
    return 0;
}
