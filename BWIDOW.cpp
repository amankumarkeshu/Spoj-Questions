#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>n;
		vector<int> a(n),b(n);
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j];
		}
		int maxi=0,ind=-1;
		for(int j=0;j<n;j++){
			if(a[j]>maxi){
				maxi=a[j];
				ind=j+1;
			}
		}
		//cout<<" $ "<<maxi<<" "<<ind<<endl;
		bool flag=true;
		for(int j=0;j<n;j++){
			if(maxi<=b[j] && (j+1)!=ind){
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<ind<<endl;
		else
			cout<<"-1\n";
	}
	return 0;
}