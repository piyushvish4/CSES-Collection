#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+10;
const int LOG = 20;
vector<int> children[MAX_N];
int up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MAX_N];

void dfs(int a, int parent) {
	for(int b : children[a]) {
        if(b==parent) continue;
		depth[b] = depth[a] + 1;
		up[b][0] = a; // a is parent of b
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[up[b][j-1]][j-1];
		}
		dfs(b,a);
	}
}

int get_lca(int a, int b) { // O(log(N))
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	// 1) Get same depth.
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j]; // parent of a
		}
	}
	// 2) if b was ancestor of a then now a==b
	if(a == b) {
		return a;
	}
	// 3) move both a and b with powers of two
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

int main() {
	int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        children[i].push_back(x);
        children[x].push_back(i);
    }
    dfs(1,0);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<get_lca(a,b)<<"\n";
    }
}