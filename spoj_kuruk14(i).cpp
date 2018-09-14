#include<iostream>
#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define fr1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define frr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define ll long long
#define mod 1000000007
#define MAX 100000
#define ios ios_base::sync_with_stdio(false);  cin.tie(0);   cout.tie(0);
#define ld long double
using namespace std;





int main()
{
    ll i,j,m,n,t,k,p,flag=0;
   cin>>t;
    while(t--)
    {


        cin>>n;
        flag=0;

        ll a[n],b[n];
        fr(i,n)
        {b[i]=0;}
       for(i =0; i<n; i++)
        {
            cin>>a[i];


             b[a[i]]++;
        }
        //p=*max_element(a,a+n);

         fr(i,n)
        {
            if((b[i]+b[n-1-i])==2)
                flag=0;
            else
            {
                flag=1;break;
            }
            if(n%2==1)
            {
                if(b[n/2]==1)
                    flag=0;
                else{
                    flag=1;break;}
            }
        }




        if(flag==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;






    }
}
