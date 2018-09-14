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

int main()
{
    ll i,j,m,n,t,k,p,sum,y;


    while( 1 )
    {read(n);

        if(n)
            cout<<n*(n+1)*(2*n+1)/6<<endl;
        else
            break;
    }
}
