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
int main()
{

    ll b,n,i,t,x,y,p,q,c[100000];
    char a[7]={'u','m','a','n','k','u','u'};
    read(t);
    while(t--)
    {
        read(n);

        p=n;

        if(n<=5)
          printf("%c",a[n]);
        else
        {
            i=0;
        while(p>0)
        {

            q=p%5;
            c[i++]=q;


          p=p/5;


        }
        frr(x,i)
        {
            printf("%c",a[c[x]]);

        }
        }
        cout<<endl;

    }
    return 0;
}

