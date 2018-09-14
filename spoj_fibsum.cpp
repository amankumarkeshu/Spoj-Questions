#include<bits/stdc++.h>
using namespace std;
#define fr(k,n) for(int k=0; k<n;k++)
#define fr1(k,n) for(int k=1; k<n;k++)
#define llb long long int
#define mod 1000000007
#define MAX 100000
typedef long long ll;

struct mat {
    ll a,b,c,d;
};
mat multiply(mat x,mat y) {
    struct mat t = { (x.a*y.a+x.b*y.c)%mod, (x.a*y.b+x.b*y.d)%mod, (x.c*y.a+x.d*y.c)%mod, (x.c*y.b+x.d*y.d)%mod};
    return t;
}
mat nthpow(mat a,int n) {
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
    return ans%mod;
}



   int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j,m,n,t;
    llb x,y,p,s1,s2,result =0,result1=0;
    cin>> t;
    while(t--)
    {

        cin>>m >>n;
        y=fib(1,1,n+2);
         x=fib(1,1,m+1);
         //cout<<y<<" "<< x<<endl;
         y=y%mod;
         x=x%mod;

        cout<<y-x<<endl;




    }
}
