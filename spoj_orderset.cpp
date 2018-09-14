#include<bits/stdc++.h>
using namespace std;

int tree[800001];
unordered_map<int,int> m;
vector<int> a;
vector<pair<char,int> > v;


void init(int s,int e,int n){
	if(s==e){
		tree[n]=0;
		return ;
	}

	int m=(s+e)/2;
	init(s,m,n*2);
	init(m+1,e,n*2+1);
	tree[n]=tree[n*2]+tree[n*2+1];
}

void update(int s,int e,int n,int x,int y){
	if(s==e && s==x){
		tree[n]+=y;
		return ;
	}

	int m=(s+e)/2;
	if(x<=m){
		update(s,m,n*2,x,y);
	}else{
		update(m+1,e,n*2+1,x,y);
	}

	tree[n]=tree[n*2]+tree[n*2+1];
}

int query(int s,int e,int n,int l,int r){
	if(l<=s && r>=e){
		return tree[n];
	}

	int m=(s+e)/2;
	if(r<=m){
		return query(s,m,n*2,l,r);
	}else if(l>m){
		return query(m+1,e,n*2+1,l,r);
	}else{
		return query(s,m,n*2,l,r)+query(m+1,e,n*2+1,l,r);
	}
}

int search(int s,int e,int n,int x){
	if(s==e){
		return s;
	}

	int m=(s+e)/2;
	if(tree[n*2]>=x){
		return search(s,m,n*2,x);
	}else{
		return search(m+1,e,n*2+1,x-tree[n*2]);
	}
}

int main(){
	int i,j,k,x,y,z,n,ans;
	scanf("%d",&n);

    m.clear();
    a.clear();
    v.clear();

	char c;
	for(i=1;i<=n;i++){
		cin>>c;
        scanf("%d",&j);
		v.push_back(make_pair(c,j));
		m[j]=1;
	}

	for(auto u:m){
		a.push_back(u.first);
	}

	sort(a.begin(),a.end());

	for(i=0;i<a.size();i++){
		m[a[i]]=i+1;
	}

	init(1,a.size(),1);

	for(i=0;i<n;i++){
		if(v[i].first=='I'){
			if(query(1,a.size(),1,m[v[i].second],m[v[i].second])==0){
				update(1,a.size(),1,m[v[i].second],1);
			}
		}else if(v[i].first=='D'){
			if(query(1,a.size(),1,m[v[i].second],m[v[i].second])){
				update(1,a.size(),1,m[v[i].second],-1);
			}
		}else if(v[i].first=='K'){
			ans=tree[1]>=v[i].second?search(1,a.size(),1,v[i].second):-1;
			if(ans!=-1){
				printf("%d\n",a[ans-1]);
			}else{
				printf("invalid\n");
			}
		}else{
			j=lower_bound(a.begin(),a.end(),v[i].second)-a.begin();
			j--;

			if(j<0){
				printf("0\n");
			}else{
	            printf("%d\n",query(1,a.size(),1,1,m[a[j]]));
			}
		}
	}
}
