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
    scanf("%lld ",&a);
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
void read(vll &oneD){

	for(ll i=0;i<oneD.size();i++){

		read(oneD[i]);

	}

}

void read(vvll &twoD){

	for(ll i=0;i<twoD.size();i++){

		read(twoD[i]);

	}

}


void write(vll &oneD)
{
    for(ll i=0;i<oneD.size();i++)
    {

		printf("%lld ",oneD[i]);
    }

	printf("\n");

}

void write(vvll &twoD)
{

	for(ll i=0;i<twoD.size();i++)
        {
            write(twoD[i]);
		}
}

void write(vpll &oneDP){

	fr(i,oneDP.size())
	{

		printf("%lld %lld\n" , oneDP[i].fst , oneDP[i].scd);

	}

}

void write(map< ll , ll > &mpp){

	for(map<ll , ll >::iterator it = mpp.begin() ; it != mpp.end() ; it++)
    {

		cout<<it->fst<<" : "<<it->scd<<endl;

	}

	cout<<endl;

}


bool sortbysecdesc ( const pll &a , const pll &b)
{
    return  (a.scd > b.scd );
}
bool sortbysecasc( const pll &a, const pll &b )
{
    return (a.scd < b.scd);
}

int main()
{
    ll a,x,m,i,j,n,t,k,p,flag=0;
   cin>>t;
    while(t--)
    {


        cin>>x>>a;
        n=a-x-1;
        m=(2*n)*(a)+n-(n*n);
        if(x==a)
            cout<<'0'<<endl;
        else
            cout<<m/2<<endl;
    }
}




