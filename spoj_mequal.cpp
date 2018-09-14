#include<bits/stdc++.h>
#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define ll long long
using namespace std;
void read( ll &a)
{
    scanf("%lld",&a);
}
void write( ll &n)
{
    printf("%lld\n",n);
}

int main()
{
    ll i,j,m,n,t,k,p,sum;
    read(t);
    while(t--)
    {
        read(n);
        ll a[n];
        sum=0;
        fr(i,n)
        {
            read(a[i]);
            sum+=a[i];
        }
        //cout<<sum<<endl;
        if(sum % n == 0)
            write(n);
        else
             printf("%lld\n",n-1);

    }
}
