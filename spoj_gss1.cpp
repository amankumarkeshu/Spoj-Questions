#include <bits/stdc++.h>

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

#define vfind(v,x) (find(all(v),x) != (v).end())

#define clr(c) (c).clear()

#define cres(c,n) (c).clear(),(c).resize(n)

#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define fst first

#define scd second

#define eb(a) emplace_back(a)

#define ef(a) emplace_front(a)

#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))

#define fr1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))

#define frr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))

#define frab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))



#define mst(A) memset( (A) , 0 , sizeof(A) );


using namespace std;


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


ll isprime(ll N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(ll i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}


ll power(ll x, ll y , ll m){

    long long int res = 1;

    x = x % m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res =(res*x)%MOD;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x)%MOD;
    }
    return res;
}


ll modinv(ll x , ll mod = MOD){

	return power(x , mod - 2 , mod);

}
////////////////////////////////////////////////////////////////////////////////
struct seg_tree{
ll pre,suff,sum,max_sum;

};
seg_tree tree[200005],pree;
ll n,m;

ll A[50005];

void init( ll n)
{
    fr(i,n)
    {
        tree[i].max_sum=INT_MIN;
        tree[i].pre=INT_MIN;
        tree[i].sum=INT_MIN;
        tree[i].suff=INT_MIN;
    }
    pree=tree[0];
}

seg_tree build( ll pos, ll tl,ll tr)

{
    if(tl== tr)
    {
        tree[pos].sum=A[tl];
        tree[pos].max_sum=A[tl];
        tree[pos].suff=A[tl];
        tree[pos].pre=A[tl];
        return tree[pos];
    }

     ll mid=tl+(tr-tl)/2;

    build(2*pos+1,tl,mid);
    build(2*pos+2,mid+1,tr);

    tree[pos].sum=tree[2*pos+1].sum+tree[2*pos+2].sum;
    tree[pos].pre= max(tree[2*pos+1].pre, tree[2*pos+1].sum+tree[2*pos+2].pre);
    tree[pos].suff= max(tree[2*pos+2].sum+tree[2*pos+1].suff, tree[2*pos+2].suff);

      tree[pos].max_sum=max(max(tree[pos].pre,max(tree[pos].suff,tree[2*pos+1].suff+tree[2*pos+2].pre))
                            ,max(tree[2*pos+1].max_sum,tree[2*pos+2].max_sum));
        return tree[pos];

}

seg_tree query(ll pos, ll tl ,ll tr, ll ql ,ll qr)
{

    if(qr <tl || tr<ql)
    {
         seg_tree y;
        y.pre=y.suff=y.sum=y.max_sum=INT_MIN;
        return y;
    }

    if(tl >=ql && qr >= tr)
        {
            return tree[pos];
        }

        ll mid=tl+(tr-tl)/2;

    seg_tree t1=query(2*pos+1,tl,mid,ql,qr);
    seg_tree t2=query(2*pos+1+1,mid+1,tr,ql,qr);

    seg_tree gree;
    gree.sum=t1.sum+t2.sum;
    gree.pre= max(t1.pre, t1.sum+t2.pre);
    gree.suff= max(t2.sum+t1.suff, t2.suff);

    gree.max_sum=max({gree.suff,gree.pre,
                         t1.suff+t2.pre,
                          t1.max_sum,t2.max_sum });

        return gree;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("allo.txt","r",stdin);
    #endif
      //  freopen("out.txt","w",stdout);




    ll a,b,c,d;
    ll k,l,p,q,r,s,t,x,y;

        //cin>>t;while(t--){


        cin>>n;
        fr(i,n)
        {

            cin>>A[i];
            //cout<<A[i];
        }
        cin>>m;
      // init(n);
         build(0,0,n-1);
        while(m--)
        {
            cin>>l>>r;
           pree=query(0,0,n-1,l-1,r-1);
            cout<<pree.max_sum<<endl;

        }

        fr(i,2*n+1)
        {
            cout<<tree[i].pre<<" "<<tree[i].suff<< " "<<tree[i].sum<<" "<<tree[i].max_sum<<endl;
        }









}


/*
3
3

3 -1 -1 -5
10 9 10 9
3 -1 3 -1
-4 -4 -4 -4
5 5 -1 -1
10 10 10 10
-4 -4 -4 -4
3 3 3 3
0 0 0 0
0 0 0 0
5 5 5 5
-6 -6 -6 -6*/









