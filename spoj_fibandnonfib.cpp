#include <cstdio>
#include <unordered_map>
using namespace std;

typedef long long int ll;

ll M = 1000000007;

ll mulmod(ll a, ll b)       //modular multiplication
{
    ll x = 0;
    ll y = a%M;
    while(b>0)
    {
        if(b%2)
            x = (x+y)%M;
        y = (y+y)%M;
        b/=2;
    }
    return x%M;
}

ll modulo(ll a, ll b)       //modular exponentiation
{
    ll x = 1;
    ll y = a;
    while(b)
    {
        if(b%2)
            x = mulmod(x,y);
        y = mulmod(y,y);
        b/=2;
    }
    return x%M;
}

unordered_map<ll,ll> Fib;

ll fibo(ll n)       //n+1 th fibonacci number
{
    if(n<2)
        return 1;
    if(Fib.find(n) != Fib.end())
        return Fib[n];
    Fib[n] = (fibo((n+1) / 2)*fibo(n/2) + fibo((n-1) / 2)*fibo((n-2) / 2)) % M;
    return Fib[n];
}

ll nonfibo(ll n)        //nth non-fibonacci number
{
    ll a = 1, b = 2, c = 3;
    while(n>0)
    {
        a = b;
        b = c;
        c = a+b;
        n-=(c-b-1);
    }
    n+=(c-b-1);
    return n + b;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",modulo(nonfibo(n),fibo(n-1)));
    }
    return 0;
}
