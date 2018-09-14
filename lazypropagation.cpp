/**
* In this code we have a very large array called arr, and very large set of operations
* Operation #1: Increment the elements within range [i, j] with value val
* Operation #2: Get max element within range [i, j]
* Build tree: build_tree(1, 0, N-1)
* Update tree: update_tree(1, 0, N-1, i, j, value)
* Query tree: query_tree(1, 0, N-1, i, j)
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
int A[MAXN];
int tree[4 * MAXN];  // 4 * size of array would suffic as the size of segment tree.


/**
**
**
**  Builds segment tree in O(number of nodes)
**  number of nodes are approximated by 4 * N
**
**  segL is left boundary of segment stored in the node
**  segR is right boundary of segment stored in the node
**
**
***/
void build_tree(int node,int segL,int segR){
    if( segL > segR) return ;
    if(segL == segR){ //leaf node
        tree[node] = A[segL];
        return;
    }
    int mid=(segL + segR) / 2;
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;
    build_tree(leftNode, segL, mid);
    build_tree(rightNode, mid + 1, segR);
    tree[node] = max(tree[leftNode], tree[rightNode]);
}


void relax(int node){
    if(lazy[node] != 0){
        //passing on laziness to children
        tree[node] += lazy[node];
        if(a != b){
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node]=0;
    }
}

/**
**
**
**  updates segment tree
**
**  segL is left boundary of segment stored in the node
**  segR is right boundary of segment stored in the node
**
**  ql is the left boundary of query range
**  qr is the right boundary of query range
**
**  `value` is the value to be added in range [ql..qr]
**
***/
void update_tree(int node, int segL, int segR, int ql, int qr, int value){
    if(segL > segR || segL > qr || segR < ql) return;         //range out of segment range
    relax(node);
    if(ql <= segL && segR <= qr){
        tree[node] += value;
        if(segL != segR){
            lazy[2 * node] += value;
            lazy[2 * node + 1] += value;
        }
        return;
    }

    int mid=(segL + segR) / 2;
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;

    update_tree(leftNode, segL, mid, ql, qr, value);
    update_tree(rightNode, mid + 1, segR, ql, qr, value);
    tree[node] = max(tree[leftNode], tree[rightNode]);
}
/**
**
**
**  queries segment tree
**
**  segL is left boundary of segment stored in the node
**  segR is right boundary of segment stored in the node
**
**  ql is the left boundary of query range
**  qr is the right boundary of query range
**
**
***/
int query_tree(int node, int segL, int segR, int ql, int qr) {
    if(segL > segR || segL > qr || segR < ql) return -INF;  //out of the range
    relax(node);
    if(ql <= segL && qr >= segR) return tree[node];     // segment range entirely in the query.
    
    int mid=(segL + segR) / 2;
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;

    return max(query_tree(leftNode, segL, mid, ql, qr), query_tree(rightNode, mid + 1, segR, ql, qr));
}
int main(){
    int N, Q; cin >> N >> Q;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    //build the tree
    build_tree(1, 0, N - 1);
    for(int i = 0;i < Q;i++){
        int type, l, r, k;
        cin >> type;
        switch(type){
            case 1: 
                    //query to add k in range [l..r]
                    cin >> l >> r >> k;
                    update_tree(1, 0, N - 1, l, r, k);
            break;
            case 2: 
                    //query to print max of range [l..r]
                    cin >> l >> r;
                    cout << query_tree(1, 0, N - 1, l, r) << "\n";
            break;
        }
    }
    return 0;
}
