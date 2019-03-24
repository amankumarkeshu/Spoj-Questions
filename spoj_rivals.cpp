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

#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define fst first

#define scd second



#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))

#define fr1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))

#define frr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))

#define frab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))



#define mst(A) memset( (A) , 0 , sizeof(A) );



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

void Seive(){

	const ll maxn = 1000005;

	seive.resize(maxn);
	fr(i,maxn) seive[i] = i;

	seive[1] = -1;

	seive[0] = -1;

	frab(i,2,maxn,1)   if(i == seive[i]) for(ll j = 2*i ; j < maxn ; j+=i) if(seive[j] == j) seive[j] = i;

}



ll power(ll x, ll y , ll m){

	if(y == 1)   return x%m;

	if(y == 0) return 1;

	if(y&1) return (x*power((x*x)%m , (y-1)/2 , m))%m;

	return power((x*x)%m , y/2 , m)%m;

}
 ll P [2000005],inv[2000005],ifact[2000005];
ll mod_Inverse(ll a)
{
    ll n=1000000005,ans =1;
    while(n)
    {
         if(n&1)
            ans = (ans*a)%MOD;
         a=(a*a)%MOD;
         n/=2;

    }
    return ans;


}


ll modinv(ll x , ll mod = MOD){

	return power(x , mod - 2 , mod);

}
ll modinv(ll n)
{


}

void precomputefactorial()
{
    P[0]=1;P[1]=1;
    for(int i=2;i< 2000005;i++)
    {
        P[i]=(i*P[i-1])%MOD;
        //cout<<P[i]<<" ";
    }
    ifact[0]=1;
    for(int i=1;i<2000006;i++)
    {
        inv[i]=mod_Inverse(i)%MOD;
        ifact[i]=(1LL*ifact[i-1]*inv[i])%MOD;
       // cout<<mod_Inverse(ifact[i])<<" ";
    }


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,t,n,x,y,m,ng,b;


    precomputefactorial();
           read(t);
           while(t--)
        {
              read(x,y);
              //cout<<mod_Inverse(P[x])<<" "<<mod_Inverse(P[y])<<endl;
             // ll temp = (mod_Inverse(P[x])*mod_Inverse(P[y]))%MOD;
             // ll res= (temp*P[x+y])%MOD;
             //cout<<x<<" "<<y<<endl;

             cout<<((P[x+y]%MOD)*(1LL*ifact[y]%MOD*ifact[x]%MOD)%MOD)%MOD<<endl;
            //cout<<res<<endl;

        }


return 0;

}
