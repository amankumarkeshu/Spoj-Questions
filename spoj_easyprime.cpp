#include<bits/stdc++.h>
#define ll long long

#define ld long double

#define vll vector<ll>
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))

#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))

#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))

#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))



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

vll seive;

void Seive()
{

	const ll maxn = 1000005;

	seive.resize(maxn);

	forn(i,maxn) seive[i] = i;

	seive[1] = -1;

	seive[0] = -1;

	forab(i,2,maxn,1) if(i == seive[i]) for(ll j = 2*i ; j < maxn ; j+=i) if(seive[j] == j) seive[j] = i;

}

// Driver Program
int main()
{
    int x, y;
    int a,c,p,q ,b,t;
    read(t);
    int k=0;
    while(t--)
    {
        read(a,b);


  }
        printf("%d %d\n",p,q);


    }
    return 0;

}

