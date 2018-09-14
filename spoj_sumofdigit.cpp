#include<bits/stdc++.h>
using namespace std;
int main(){
int t,i,sum,n;
cin>>t;
while(t--)
{
    string s ;
    cin>>s;
    n=s.length();
    sum=0;
    for( i=0;i<n;i++)
    {
        int x = (int)s[i];

        x-=48;
           //cout<<x<<" ";

    sum+=x;
    }

    cout<<sum<<endl;
}
}
