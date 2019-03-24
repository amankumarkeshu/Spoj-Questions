#include<bits/stdc++.h>


void read(int &a)
{
    scanf("%d",&a);
}
void read(int &a,int &b)
{
    scanf("%d %d",&a,&b);
}
void read(int &a,int &b,int &c)
{
    scanf("%d %d %d",&a,&b,&c);
}
//r extended Euclidean Algorithm
int gcdExtended(int a, int b, int &x, int &y)
{
    // Base Case
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, x1, y1);

    // Update x and y using results of recursive
    // call
    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

// Driver Program
int main()
{
    int x, y;
    int a,c ,b,t;
    read(t);
    int k=0;
    while(t--)
    {k++;
    read(a,b,c);
    int g = gcdExtended(a, b, x, y);
   // printf("gcd(%d, %d) = %d,%d,%d", a, b, g,x,y);
    if(c%g == 0){
         printf("Case %d: Yes\n",k);
        continue;}
    if(g==1)
    {
        if(c%a ==0 || c%b==0){
             printf("Case %d: Yes\n",k);
             continue;}
    }
    else
    printf("Case %d: No\n",k);



    }
    return 0;

}

