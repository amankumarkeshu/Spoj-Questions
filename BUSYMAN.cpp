#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct event{
	int st;
	int en;
};

bool operator<(event a,event b)
{
	if(a.en<b.en)
		return true;
	else if(a.en==b.en){
		if(a.st<b.st)
			return true;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<event> a(n);
		for (int i = 0; i < n; i++)
		{
			cin>>a[i].st>>a[i].en;
	
			
		}
		sort(a.begin(),a.end());
		
		int maxi=0;
		
		for (int i = 0; i < n;)
		{
			maxi++;
			int j = i+1;
			for (; a[j].st<a[i].en && j<n ; j++)
			{
				
			}
			i=j;
		}
		
		cout<<maxi<<endl;
		
		
	}
	return 0;
}
