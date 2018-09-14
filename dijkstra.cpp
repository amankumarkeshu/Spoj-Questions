/**
**
** Dijkstra's algorithm
** Complexity : O((E+V)logV)
** Implemented using priority queue. (It can also be implemented using heaps.)
**
** Sample Problem : http://www.spoj.com/problems/EZDIJKST/
**
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 1e6 + 10;
const LL MOD = 1e9 + 7;
const LL INF = 1e15;


typedef vector<pair<LL, LL> > Graph;

//---------------------------------------------------------------
LL dis[MAXN];
inline void dijkstra(Graph G[],LL N,LL src){
	for(LL i = 1;i <= N;++i) dis[i] = INF;
	dis[src] = 0;
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > PQ;
	PQ.push(make_pair(0, src));
	while(!PQ.empty()){
        cout << PQ.top().first << " " << PQ.top().second << "\n";
		LL cur = PQ.top().second; PQ.pop();
		LL sz = G[cur].size();
		for(LL i = 0;i < sz;++i){
			pair<LL, LL> curPair = G[cur][i];
			LL next = curPair.first;
			LL w = curPair.second;
			if(dis[next] > dis[cur] + w){
                //This condition will always make algorithm in negative weights but not in negative cycle.
				dis[next] = dis[cur] + w;
				PQ.push(make_pair(dis[next], next));
			}
		}
	}
}
//---------------------------------------------------------------
 
int main(){
	LL tc; cin >> tc;
    while(tc--){
    	LL N, K; cin >> N >> K;
    	Graph G[N + 1];
    	while(K--){
    		LL u, v, c; cin >> u >> v >> c;
    		G[u].push_back(make_pair(v,c)); // Directed Graph
    		// G[v].push_back(make_pair(u,c));
    	}

    	LL A;cin >> A;
    	dijkstra(G, N, A);
    	/*cout << "Final result\n";
    	for(LL i = 1;i <= N;++i){
    		cout << i <<  " " << dis[i] << "\n";
    	}*/
    	LL B;cin >> B;
    	if(dis[B] == INF){
    		printf("NO\n");
    	}else{
    		printf("%lld\n",dis[B]);
    	}
    }
    return 0;
}
/**
Fail Test Case
1
4 4
1 2 5
1 3 2
2 3 -10
3 4 10
1 4

Sample Test Case :
1
5 7
1 2 2
1 3 1
1 4 6
2 5 1
4 5 5
3 4 4
3 5 2
1 5
*/