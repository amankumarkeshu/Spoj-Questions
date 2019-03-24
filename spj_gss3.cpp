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



////////////////////////////////////////////////////////////////////////////////

struct  tt
{
    ll pre,suf,sum,ma;
};
ll A[50005];
tt tree[200005];
tt build(ll pos, ll l,ll r)
{
    if(l==r)
    {
       tree[pos].pre=A[l];
       tree[pos].suf=A[l];
       tree[pos].sum=A[l];
       tree[pos].ma=A[l];
       return tree[pos];
    }


   ll mid=l+(r-l)/2;
   //cout<<pos<<" " <<l<<" " <<r<< " "<<mid<<endl;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);

    tree[pos].pre=max( tree[2*pos].sum+tree[2*pos+1].pre ,tree[2*pos].pre);
    tree[pos].suf=max(tree[2*pos].suf+tree[2*pos+1].sum,tree[2*pos+1].suf);
    tree[pos].sum=tree[pos*2].sum+tree[2*pos+1].sum;
    tree[pos].ma=max({tree[pos].pre,tree[pos].suf,tree[2*pos].ma,tree[2*pos+1].ma,
                     tree[2*pos].suf+tree[2*pos+1].pre});

        return tree[pos];
}

tt  query(ll pos, ll ql , ll qr , ll l ,ll r)
{
    if(l>qr || r<ql)
    {
        tt t;
        t.pre=INT_MIN;
         t.suf=INT_MIN;
          t.sum=INT_MIN;
           t.ma=INT_MIN;

           return t;

    }
    if(ql<=l&& r<=qr)
    {
        return tree[pos];
    }

     ll mid=l+(r-l)/2;

    tt t1=query(2*pos,ql,qr,l,mid);
    tt t2=query(2*pos+1,ql,qr,mid+1,r);

    tt gree;
    gree.pre=max(t1.pre,t1.sum+t2.pre);
    gree.suf=max(t2.suf,t2.sum+t1.suf);
    gree.sum=t1.sum+t2.sum;
    gree.ma=max({t1.ma,t2.ma,gree.pre,gree.suf,t1.suf+t2.pre});

    return gree;
}
tt update(ll pos,ll l, ll r, ll idx, ll k )
{

    if(l==r)
    {
        tree[pos].pre=k;
        tree[pos].suf=k;
        tree[pos].sum=k;
        tree[pos].ma=k;
         return tree[pos];


    }

   ll mid=(r+l)/2;
    if(idx<=mid)
   update(2*pos ,l,mid,idx,k);
   else
   update(2*pos+1 ,mid+1,r,idx,k);
  tree[pos].pre=max( tree[2*pos].sum+tree[2*pos+1].pre ,tree[2*pos].pre);
    tree[pos].suf=max(tree[2*pos].suf+tree[2*pos+1].sum,tree[2*pos+1].suf);
    tree[pos].sum=tree[pos*2].sum+tree[2*pos+1].sum;
    tree[pos].ma=max({tree[pos].pre,tree[pos].suf,tree[2*pos].ma,tree[2*pos+1].ma,
                     tree[2*pos].suf+tree[2*pos+1].pre});
     return tree[pos];


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

        //cin>>t;while(t--){    map<ll,ll> M;


        cin>>n;
        fr1(i,n)
        {

            cin>>A[i];
            //cout<<A[i];
        }
        build(1,1,n);
        cin>>m;
        while(m--)
        {
            cin>>x;
           if(x==1)
            {
                 cin>>l>>r;
                 tt abc=query(1,l,r,1,n);
                 cout<<abc.ma<<endl;
            }
            else{
                    ll i,k;

                cin>>i>>k;
                update(1,1,n,i,k);
            }
        }





}












