
#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define tt(t) read(t); while(t--)

#define endl '\n'

#define vll vector<ll>

#define vvll vector< vll >

#define pll pair<ll ,ll >

#define pss pair < string , string >

#define vpll vector< pll >

#define vpss vector< pss >

#define mp make_pair

#define pb push_back

#define MOD 1000000007

#define inf 1e18;

#define find(v,x) ((v).find(x) != (v).end())

#define vfind(v,x) (find(all(v),x) != (v).end())

#define clr(c) (c).clear()

#define cres(c,n) (c).clear(),(c).resize(n)

#define ios ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)



#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define fst first

#define scd second



#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))

#define fr1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))

#define frr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))

#define frab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))



#define mst(A) memset( (A) , 0 , sizeof(A) );

template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }




using namespace std;



void read(ll &x){

	scanf("%lld",&x);

}

void read(ll &x,ll &y){

	scanf("%lld %lld",&x,&y);

}

void read(ll &x,ll &y,ll &z){

	scanf("%lld %lld %lld",&x,&y,&z);

}

void read(ll &x,ll &y,ll &z,ll &w){

	scanf("%lld %lld %lld %lld",&x,&y,&z,&w);

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






void write(vll &oneD){

	for(ll i=0;i<oneD.size();i++){

		printf("%lld ",oneD[i]);

	}

	printf("\n");

}

void write(vvll &twoD){

	for(ll i=0;i<twoD.size();i++){

		write(twoD[i]);

	}

}

void write(vpll &oneDP){

	fr(i,oneDP.size()){

		printf("%lld %lld\n" , oneDP[i].fst , oneDP[i].scd);

	}
	cout<<"\n";

}

void write(map< ll , ll > &mpp){

	for(map<ll , ll >::iterator it = mpp.begin() ; it != mpp.end() ; it++){

		cout<<it->fst<<" : "<<it->scd<<endl;

	}

	cout<<endl;

}
bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first == b.first)
        return (a.scd >= b.scd);

    return (a.first < b.first);
}

ll A[100005];
vll seive;
vll primes;

void Seive(){

	const ll maxn = 100005;

	seive.resize(maxn);
	fr(i,maxn) seive[i] = 1;

	//seive[1] = 0;

	//seive[0] = 0;

	for(ll i=2;i*i<maxn;i++)
	{
	     if(seive[i]==1 )
            {
                for(ll j = i*i ; j <maxn ; j+=i)
                {
                         seive[j] = 0;
                }
            }
    }
	primes.pb(2);
	for(ll i=3;i<maxn;i+=2)
    {
        if(seive[i])
            primes.pb(i);
    }
}

void printprime(ll l,ll r)
{
    if(l<2)
        l=2;
    bool isprime[r-l+1];
    fr(i,r-l+1)
        isprime[i]=true;

    for( int i =0; primes[i]*primes[i] <= r; i++)
    {
        // Smaller  or  equal value to l
        //cout<<primes[i]<<"primes[i] ";
        ll base = (l/primes[i])*primes[i];
        if(base < l)
        {
            base =base + primes[i];
        }

        //Mark all multiples of primes [i] as false
        for( ll j= base ;j<=r; j+=primes[i])
        {
            isprime[j-l]= false;
        }
        // There may be a case where base itsef a prime
        if(base == primes[i])
            isprime[base-l]=true;

    }
    for( int  i=0; i<r-l+1; i++)
    {
        if(isprime[i]==true)
            cout<<i+l<<endl;
    }

}

ll isprime(ll N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(ll i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}
ll power(ll x, ll y , ll m){

    long long int res = 1;

    x = x % m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = mulmod(res,x,m);

        // y must be even now
        y = y>>1; // y = y/2
        x = mulmod(x,x, m);
    }
    return res;
}


ll modinv(ll x , ll mod = MOD){

	return power(x , mod - 2 , mod);

}
//r extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
    // Base Case
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, x1, y1);

    // Update x and y using results of recursive
    // call
    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

// function to find the solution
 vpll pp;
ll solution(ll a,ll b, ll n)
{

    // traverse for all possible values
    for (int i = 0; i * a <= n; i++) {

        // check if it is satisfying the equation
        if ((n - (i * a)) % b == 0) {
                //pp.first=i;
               // pp.second=(n-(i*a))/b;
                pp.pb({i,(n-(i*a))/b});
            //cout << "x = " << i << ", y = "<< (n - (i * a)) / b;
            return 1;
        }
    }

    return 0;
}

// Driver Program
ll fact[1000001];
int main()
{
     ios;
   ll a,b,c,d;
    ll k,l,m,n,p,q,r,s,t,x,y;
    ll A[100001],B[100001];
    fact[0]=1;
    /*fr1(i,1000001)
    {
        fact[i]=(i*fact[i-1])%MOD;
    }*/

   cin>>t;
   while(t--)
    {
        pp.clear();


       cin>>n>>c;

       if(isprime(n))
        a= n+1;
       else a= n ;

        if(isprime(n-1)) b= n+1;
        else b =n ;


        if(solution(a,b,c))
        {

        cout<<"Haanji\n";
        cout<<pp[0].first<<" "<<pp[0].second<<endl;
        }


        else
        {
         cout<<"Naaji\n";
          //cout<<x<<" "<<y<<endl;
        }





        /*





    ll g = gcdExtended(a, b, x, y);
    printf("gcd(%lld, %lld) = %lld,%lld,%lld\n", a, b, g,x,y);


p=a*x+b*y;
cout<<p<<endl;

    if(c%p==0)
    {
        cout<<"Haanji\n";
        cout<<x<<" "<<y<<endl;
    }
    else
    {
         cout<<"Naaji\n";
          //cout<<x<<" "<<y<<endl;
    }
    */


    }
    return 0;

}
