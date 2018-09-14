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
void findall(string x)
{
    ll m,n;
    unordered_multiset<char> window;
    unordered_multiset<char> s;
    fr(ll i=0;i<n; i++)
    {
        window.insert(x[i]);
        if(window == s)
        {

        }
        auto itr = window.find(x[i]);
        if(itr!= window.end())
        {
            window.erase(itr);

        }
        window.insert(x[i]);
    }


}

int main()
{
    ll i,j,m,n,t,k,p;
    read(t);
    while(t--)
    {


        read(n);
        vll vect;
        ll a[n];
        fr(i,n)
        {
            read(vect[i]);
        }

        write(vect);
        fr(i,n)
        {
            if(vect[i]==i || vect[i]==n-i)
                flag=0;
            else
                flag=1;



        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;






    }
}




