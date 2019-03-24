#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

typedef long long Long;


const int MAXL = 30;



long long fib[MAXL];

//How much ones are if you write down the representation of first fib[i]-1 natural numbers
long long dp[MAXL];

void buildDP()
{
    fib[0] = 1;
    fib[1] = 1;
    FOR(i,2,MAXL)
        fib[i] = fib[i-1] + fib[i-2];


    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    FOR(i,3,MAXL)
        dp[i] = fib[i-2] + dp[i-2] + dp[i-1];
}

//How much ones are if you write down the representation of first n natural numbers
Long solNumber(Long n)
{
    if(n == 0)
        return n;
    Long res = 0;
    RREP(i,MAXL)
        if(n>=fib[i])
        {
            n -= fib[i];
            res += dp[i];
            res += (n+1);
        }
    return res;
}

int solManual(Long num, Long n)
{
    int cr = 0;

    RREP(i,MAXL)
    {
        if(n == 0)
            break;

        if(num>=fib[i])
        {
            num -= fib[i];
            ++cr;
        }

        if(cr != 0)
            --n;
    }
    return cr;
}

Long num(int l)
{
    if(l<=2)
        return 1;
    return fib[l-1];
}

Long sol(Long n)
{
    //length of fibonacci representation
    int l = 1;
    //totatl acumulated length
    int cl = 0;
    while(num(l)*l + cl <= n)
    {
        cl += num(l)*l;
        ++l;
    }
    //Number of digits, that represent numbers with maxlength
    Long nn = n - cl;

    //Number of full numbers;
    Long t = nn/l;

    //The last full number
    n = fib[l] + t-1;

    return solNumber(n) + solManual(n+1, nn%l);



}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    buildDP();

    Long n;
    cin>>n;

        cout<<sol(n)<<endl;
    return 0;
}
