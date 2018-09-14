
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

ll n;
bool possible(ll mid)
{
    ll res =n, eat=0;
    while(res)
    {
        ll tk =min(mid,res);
        eat+= tk;
        res-=tk;
        res-=res/10;

    }
    return (2*eat>=n);
}

 ll A[202020];
int binarysearch(ll num,ll n)
{
    ll low=0,high=n;
    while(low<=high)
    {



    ll mid= (low+high)/2;
    if(num == A[mid])
        return true;
    else if(A[mid]>num) high =mid-1;
    else low= mid+1;
    }
    return false;



}

int main()
{

    ll t,low,high,r,cnt=0;
    ll best =0,k,mid,p=0;

    vpll events;
     read(n,k);
    fr(i,n) {
      cin>>A[i];
    }
    sort(A,A+n);

    fr(i,n)
    {
        if(binarysearch(A[i]+k,n))
            cnt++;
    }
    cout<<cnt;
}
















