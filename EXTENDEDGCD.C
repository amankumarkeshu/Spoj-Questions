// C program to demonstrate working of extended
// Euclidean Algorithm
#include <stdio.h>


void read(int &a)
{
    scanf("%d",&a);
}
void read(int &a,int &b)
{
    scanf("%d %d",&a,&b);
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
     ios;
    ll a,b,c,d;
    ll k,l,m,n,p,q,r,s,t,x,y;
    ll A[100001],B[100001];
    fact[0]=1;
    fr1(i,1000001)
    {
        fact[i]=(i*fact[i-1])%MOD;
    }

    tt(t)
    {

        read(n,c);

       if(fact[n-1]%n == n-1)
        a= n+1;
       else a= n ;

        if(fact[n-2]%(n-1) == n-2) b= n+1;
        else b =n ;

    int g = gcdExtended(a, b, x, y);
    printf("gcd(%d, %d) = %d,%d,%d", a, b, g,x,y);


    }
    return 0;

}
