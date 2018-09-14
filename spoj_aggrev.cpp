
#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define vll vector<ll>

#define vvll vector< vll >

#define pll pair<ll ,ll >

#define pss pair < string , string >

#define vpll vector< pll >

#define vpss vector< pss >

#define mp make_pair

#define pb push_back

#define MOD 1000000007

#define inf 1e9;



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

	scanf("%lld%lld",&x,&y);

}

void read(ll &x,ll &y,ll &z){

	scanf("%lld%lld%lld",&x,&y,&z);

}

void read(ll &x,ll &y,ll &z,ll &w){

	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);

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

}

void write(map< ll , ll > &mpp){

	for(map<ll , ll >::iterator it = mpp.begin() ; it != mpp.end() ; it++){

		cout<<it->fst<<" : "<<it->scd<<endl;

	}

	cout<<endl;

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

ll power(ll x, ll y , ll m){

	if(y == 1) return x%m;

	if(y == 0) return 1;

	if(y&1) return (x*power((x*x)%m , (y-1)/2 , m))%m;

	return power((x*x)%m , y/2 , m)%m;

}



ll modinv(ll x , ll mod = MOD){

	return power(x , mod - 2 , mod);

}
bool possible(ll n ,ll k ,ll mid)
{
    ll p=1,last =A[0];
    for(int i=1; i<n && p<k; i++)
    {
        if(A[i]-last>=mid)
        {
            p++;
            last= A[i];

        }
    }
    return (p==k);
}


int main()
{

    ll t,n,low,high,r;
    ll a,best =0,k,mid;
    read(t);
    while(t--)
    {
        read(n,k);
        fr(i,n)
            read(A[i]);
        sort(A,A+n);
        best = low= 0;
        high=1e9;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(possible(n,k,mid))
            {
                  setmax(best,mid);
                  low=mid+1;
            }
            else high=mid-1;
        }
        cout<<best<<endl;
    }



}










