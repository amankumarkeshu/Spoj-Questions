#include<bits/stdc++.h>
#define ll long long
#define fr for(ll (i)=0;(i)< (n);i++)
#define fr1 for(ll (i)=1;(i)<= (n);i++)
using namespace std;
void read( ll &a)
{
    scanf("%lld",&a);
}
void read( ll &a, ll &b)
{
    scanf("%lld %lld",&a,&b);
}





int main()
{
    ll a=0,b,c,i,j,n,k,t,sum;


    while(1)
    { sum=1;
    a=0;
    read(n);
    if(n==0)
        break;


    while(sum<=n)
    {

        sum=sum*2;
        a++;

    }
    cout<<a-1<<endl;
    }
}
