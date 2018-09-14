#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define fr(x,in,n,r) for(x=in;x<n;x+=r)
#define ifr(x,n) for(x=0;x<n;x++)
#define dfr(x,n) for(x=n-1;x>=0;x--)
#define present(container, element) ((container).find(element) != ((container).end())  //all except vector
#define vpresent(container, element) (find(all(container),element) != (container).end()) //vector
#define np(c) next_permutation(all(c))
#define pp(c) prev_permutation(all(c))
#define sz(a) long long((a).size())
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pof(a) pop_front(a)
#define pob(a) pop_back(a)
#define eb(a) emplace_back(a)
#define ef(a) emplace_front(a)
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z)
#define norm(v)     sqrt(dot(v,v))     // norm = length of  vector
#define d(u,v)      norm(u-v)          // distance = norm of difference
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
typedef pair<vi,int> pvii;
typedef vector<pii> vpii;
typedef long long ll;
typedef long double ld;

struct asr
{
    ll num;
    int index;
};

bool fun(asr x,asr y)
{
    return x.num<y.num;
}

bool cal(ll *a,int n,ll s,int k)
{
    asr b[n];
    int i,j,c[n];
    ifr(i,n)
    {
        b[i].num=a[i];
        b[i].index=i;
        c[i]=1;
        //cout<<b[i].num<<" b "<<b[i].index<<endl;
    }
    sort(b,b+n,fun);

    ifr(i,n)
    {
        fr(j,max(0,b[i].index-k),min(n-1,b[i].index+k)+1,1)
        {
            // cout<<"A[v[i].scd]:"<<a[b[i].index]<<"v[i].scd "<<b[i].index<<endl;
            if(a[j]>a[b[i].index] && c[j]<=c[b[i].index])
            c[j]=c[b[i].index]+1;
            if(a[j]<a[b[i].index] && c[j]>=c[b[i].index])
            c[b[i].index]=c[j]+1;
            if(a[b[i].index]==a[j] && c[b[i].index]!=c[j])
            c[b[i].index]=c[j]=max(c[b[i].index],c[j]);
        }
    }


    ll sum=0;
    ifr(i,n)
    {
         sum+=c[i];
          cout<<c[i]<<" :sum "<<sum<<endl;
    }

    cout<<"sum:"<<sum<<endl;
    return sum<=s;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int i,n;
        ll s;
        cin>>n>>s;
        ll  a[n];
        ifr(i,n)
        cin>>a[i];
        int count=0;
        ifr(i,n+1)
        {
            bool f=cal(a,n,s,i);
            if(f)
            count++;
            else
            break;
        }
        cout<<count<<endl;
    }
	return 0;

}
