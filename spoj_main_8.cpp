#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,d,r,l,t,n,k,mx;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        ll sum=0;
        sort(A,A+n);
        r=A[n-1];
        l=0;
        if(k==1)
        {
            cout<<A[n-1]<<endl;
            continue;
        }
        //if(k>A[0])
        mx=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            sum=0;
            for(int i=n-1;i>=0;i--)
            {
                sum+=(A[i]/mid);
            }
            if(sum>=k)
            {
                l=mid+1;
                mx=max(mx,mid);
                //cout<<mid<<"MID"<<endl;
            }
            else{
                    r=mid;

            }

        }
        cout<<mx<<endl;
    }
}
