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

    long long int res = 1;

    x = x % m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % m;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % m;
    }
    return res;
}




ll modinv(ll x , ll mod = MOD){

	return power(x , mod - 2 , mod);

}

vll A[100005];
ll sum=0;
vll vect;
bool visited[100005];
//vvll A;
void dfs(ll s )
{

    visited[s] =true;

    for( int i =0; i< A[s].size(); i++)
    {
        if(visited[A[s][i]] == false)
            dfs(A[s][i]);
    }
}
void dfs_stack(ll x)
{
    stack<ll> s;
    s.push(x);

    while(!s.empty())
    {
        ll temp = s.top();
        s.pop();

        if(visited[temp] == false)
        {
            visited[temp]=true;
            for(int i=0; i<(int)A[temp].size();i++)
            {
                s.push(A[temp][i]);

            }
        }

    }
}
void initialize()
{
    fr(i,100005)
    {
        visited[i]=false;
    }
}


int main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,k,l,t,n,m,x,y,b,connected=0;


    read(t);
    while(t--)
    {
        connected=0;


           read(n,m);

           for(i=0;i<100005;i++){A[i].clear();}


            //A.resize(n);
            fr(i,m)
            {
                 cin>>x>>y;

                A[x].pb(y);
                A[y].pb(x);
            }
           /* fr(i,n)
            {
                cin>>vect[i];
            }*/

            initialize();
            fr(i,n)
            {
                if(visited[i]==false)
                {
                    dfs_stack(i);
                    connected++;// Total connected components in a graph

                }
            }
            cout <<"CONNECTED:  "<<connected<<"\n";

    }

return 0;

}

