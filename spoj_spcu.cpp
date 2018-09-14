#include<bits/stdc++.h>
#include<cmath>
#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define ll long long
#define mod 1000000007
#define vll vector<ll>
#define MAX 100000
#define ld long double
using namespace std;
void read( ll &a)
{
    scanf("%lld",&a);
}
void read( ll &a, ll &b)
{
    scanf("%lld %lld",&a,&b);
}
int main()
{
    ll n,k,t,a,sum,c=1;
    ld p,q=10,s;

    read(t);

    while(t--)
    {
        read(n);
        ll a[n];
        k=0;
        fr(i,n)
        {
            read(a[i]);
            if(a[i]>i)
                k=1;

        }
        if(k)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
}



