
#include <bits/stdc++.h>

#define ll long long

#define ld long double

#define endl '\n'

#define vll vector<ll>

#define vvll vector< vll >

#define Cout(x)        cout << #x << " " << x << endl

#define pll pair<ll ,ll >

#define vpll vector< pll >

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


ll A[1000005];
ll visited[101][101];
string s[105];
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};
ll ans=0;
  queue<pair< ll , ll  > > Q;
ll bfs(ll x, ll y , ll n , ll m)
{
    visited[x][y]=1;


    Q.push({x,y});
    while(!Q.empty())
    {

        ll x=Q.front().first;
        ll y=Q.front().second;
        char c1=s[x][y];
        Q.pop();
        fr(i,8)
        {
            ll nx= x+dx[i];
          ll ny=y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            char ch=s[nx][ny];
            if(ch==c1+1 && visited[nx][ny]==0)
            {
                Q.push({nx,ny});
              // cout<<nx<<" "<<ny<<" " <<(ll)ch<<" " <<endl;

                ans= max((ll)ch-64,ans);

                visited[nx][ny]=1;


            }


        }
    }
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
    ll k,l,m,n,p,q,r,t,x,y;

        //cin>>t;while(t--){    map<ll,ll> M; string s;

        c=0;
        while(1)
        {

        while(!Q.empty())
        {
            Q.pop();
        }
            ans=0;
            c++;




        cin>>n>>m;
        if(n==0&& m==0)
        {
            break;
        }
        fr(i,n)
        {


            cin>>s[i];
            //cout<<A[i];
        }
        ll f=0;
        fr(i,n)
        {
            fr(j,m)
            {
                if(s[i][j]=='A')
                {
                     ans=1;

                    Q.push({i,j});
                    x=i;
                    y=j;

                    f=1;

                }
            }

        }
        if(f==0)
        {
              cout<<"Case "<<c<<": "<<ans<<endl;

        }
        else
        {
             bfs(x,y,n,m);
              cout<<"Case "<<c<<": "<<ans<<endl;

        }

        fr(i,101)
        {
            fr(j,101)
            {
                visited[i][j]=0;
            }
        }



       //


        }

        //   }




}











