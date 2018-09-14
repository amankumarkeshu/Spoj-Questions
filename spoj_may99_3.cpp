#include<bits/stdc++.h>
#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define fr1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define frr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define frab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
#define vll vector<ll>
#define vvll vector< vll >
#define pll pair<ll ,ll >
#define vpll vector< pll >
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define scd second
#define MOD 1000000007
#define ll long long
#define mod 1000000007
#define MAX 100000
#define ios ios_base::sync_with_stdio(false);  cin.tie(0);   cout.tie(0);
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
void read( ll &a, ll &b,ll &c)
{
    scanf("%lld %lld %lld",&a,&b,&c);
}
ll extendedgcd(ll a,ll b,ll &x, ll &y)
{
    if(a==0)
    {
        x=0;y=1;
        return b;
    }
    ll x1,y1;
    ll g = extendedgcd(b%a,a,x1,y1);
    x = y1 + b/a *x1;
    y=y1;
    return g;
}
ll gcdExtended(ll a, ll b, ll *x,ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
int main()
{

    ll a,b,c,t,x,y,p;
    read(t);
    while(t--)
    {
        read(a,b,c);
        p = extendedgcd(a,b,x,y);
        if(c > max(a,b))
            cout<<"NO\n";
        else if(c%p != 0)
             cout<<"NO\n";
        else
             cout<<"YES\n";
    }
}

