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
void read(ll &a,ll &b,ll &c,ll &d)
{
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);

}
void write( ll &n)
{
    printf("%lld\n",n);
}
void write(vll &oneD)
{
    for(ll i=0;i<oneD.size();i++)
    {

		printf("%lld ",oneD[i]);
    }

	printf("\n");

}
struct mat {
    ll a,b,c,d;
};
mat multiply(mat x,mat y) {
    struct mat t = { (x.a*y.a+x.b*y.c)%mod, (x.a*y.b+x.b*y.d)%mod, (x.c*y.a+x.d*y.c)%mod, (x.c*y.b+x.d*y.d)%mod};
    return t;
}
mat nthpow(mat a,ll n) {
    if (n == 0){
	struct mat t = {1,0,0,1};
	return t;
    }
    if (n==1) {
	return a;
    }
    struct mat t = nthpow(a, n/2);
    t = multiply(t,t);
    if ((n%2)==1) {
	t = multiply(t,a);
    }
    return t;
}
ll fib(ll a,ll b,ll n) {
    if ( n == 0 ) {
	return -1LL;
    }
    if (n == 1) {
	return a;
    }
    if ( n== 2) {
	return b;
    }
    struct mat x = {0,1,1,1};
    //cout<<"N = "<<n-2<<endl;
    struct mat t = nthpow(x,n-2);
    //cout<<t.a<<" "<<t.b<<"\n"<<t.c<<" "<<t.d<<endl;
    ll ans = (t.c*a + t.d*b)%mod;
    return ans;
}S


int main()
{
    ll i,j,m,n,t,k,p,sum,y;
    read(t);
    while(t--)
    {
        read(n);
        ll a[7]={0,1,4,6,5,2,0};
        cout<<a[n%6]<<endl;
    }
}

