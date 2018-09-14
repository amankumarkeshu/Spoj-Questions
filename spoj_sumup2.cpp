#include<bits/stdc++.h>
using namespace std;int main(){
int t,x;cin>>t;
while(t--)
{double i,s=0;cin>>x;for(i=1;i<=x;++i) s+=(i)/(i*i*i*i + i*i + 1);
cout<<fixed<<setprecision(5)<<s<<"\n";}}
