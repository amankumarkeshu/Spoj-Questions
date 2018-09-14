/**
**
**	Kruskal's MST
**	O(M lg M)
**
**
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e4 + 10;

int parent[MXN];
int getParent(int x){
	if(x == parent[x]) return x;
	parent[x] = getParent(parent[x]);
	return parent[x];
}
void merge(int x, int y){
	int px = getParent(x);
	int py = getParent(y);
	if(px != py){
		parent[px] = py;
	}
}
int main(){
	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int> > > edges;
	// (edge_weight, (edge_from, edge_to))
	for(int i = 0;i < M;++i){
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back(make_pair(c, make_pair(u, v)));
	}
	sort(edges.begin(), edges.end());
	long long sum=0;

	//DSU intialization
	for(int i = 1;i <= N;++i){
		parent[i] = i;
	}
	for(int i = 0;i < M;++i){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int c = edges[i].first;
		if(getParent(u) != getParent(v)){
			//cout << "This edges is selected in MST (u, v, c) = " << "(" << u << ", " << v << ", " << c << ")\n";
			sum+=c;
			merge(u, v);
		}

	}
			cout<<sum<<endl;

}
