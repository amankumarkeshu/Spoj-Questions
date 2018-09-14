#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> primes;
int pl;
int a[1001];

struct primef{
	int a[1000];
	primef(){
		for (int i = 0; i < pl; i++)
		{
			a[primes[i]]=0;
		}
	}
	primef(int no){
		for (int i = 0; i < pl;)
		{
			int n=primes[i];
			if(no%n==0)
			{
				a[n]++;
				no/=n;
			}
			else{
				i++;
			}
		}
	}
	
	void print(){
		cout<<"***********************************"<<endl;
		for (int i = 0; i < pl; i++)
		{
			cout<<primes[i]<<":"<<a[primes[i]]<<"  ";
		}
		cout<<endl;
	}
	
};

primef allp[1001];

primef operator*(primef a1,int no){	
		for (int i = 0; i < pl;)
		{
			int n=primes[i];
			if(no%n==0)
			{
				a1.a[n]++;
				no/=n;
			}
			else{
				i++;
			}
		}
		return a1;
}
	
bool operator==(primef a1 , primef b1){
		for (int i = 0; i < pl; i++)
		{
			if(a1.a[primes[i]]!=b1.a[primes[i]])
				return false;
		}
		return true;
}

int fact(primef x){
	for (int i = 0; i < 1000; i++)
	{
		if(x==allp[i])
			return i;
	}
	return -1;
	
}
vector<int> factorize(int n){
	vector<int> ret;
	if(a[n]){
		ret.push_back(n) ;
		return ret;
	}
	primef x;
	
	for (int i = n; i >=2 ; i--)
	{
		x=x*i;
		int r=fact(x);
		//cout<<r<<"& "<<i<<"\n";
		if(r>1){
			vector<int> y,z;
			y=factorize(r);
			z=factorize(i-1);
			if(y.size()==0||z.size()==0){
				return ret;
			}
			ret.reserve( y.size() + z.size() ); // preallocate memory
			ret.insert( ret.end(), y.begin(), y.end() );
			ret.insert( ret.end(), z.begin(), z.end() );
			
			break;
		}
		if(a[i])
			break;
	}
	
	return ret;
	
}
int main(){
	
	
	for (int i = 0; i < 1001; i++)
	{
		a[i]=1;
	}
	a[0]=a[1]=0;
	for (int i = 2; i < 1001; i++)
	{
		if(a[i]){
			primes.push_back(i);
			for (int j = i+i; j < 1001; j+=i)
			{
				a[j]=0;
			}
		}
	}
	
	pl=primes.size();
	
	
	
	int n,temp=1;
	//cin>>n;
	for (n = 0; n < 1001; n++)
	{
	
		if(n<4||a[n]){
			//cout<<"No solution\n";
			//return 0;
			continue;
		}
			
		
		for (int i = 1; i < 1001; i++)
		{
			allp[i]=allp[i-1]*i;
		}
		
		vector <int> result;
		
		result=factorize(n);
		
		if(result.size()==0){
			//cout<<"No solution\n";
			//return 0;
			continue;
		}
		
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<"! ";
		}
		cout<<"\n";
	}
	return 0;
}

