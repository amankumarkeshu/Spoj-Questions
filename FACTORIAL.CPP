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



ll multiply(ll x, ll res[], ll res_size);
void factorial(ll n)
{
    ll res[MAX];

    // Initialize result
    res[0] = 1;
    ll res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (ll x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    //return res;

    cout << "Factorial of given number is \n";
    for (ll i=res_size-1; i>=0; i--)
        cout << res[i]%mod;
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
long long multiply(ll x, ll res[],ll res_size)
{
    ll carry = 0;  // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (ll i=0; i<res_size; i++)
    {
        ll prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry  = prod/10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}


int main()
{
    ll i,j,m,n,t,k,p,u,v;
    read(t);
    while(t--)
    {



           read(n);

                factorial(n);
                cout<<endl;
    }









}

