#include <vector>
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

// computes A * B


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

matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(int N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",modulo(nonfibo(n),fib(n)));
    }
    return 0;
}
