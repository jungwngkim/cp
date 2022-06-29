#include <iostream>
#include <vector>

#define N 50000

using namespace std;

int n, m;
int state[N];
int p[N], r[N];
vector<int> adj[N];
vector<pair<int, int>> adj2;

int find(int x) {
	return p[x] = (p[x] == x) ? x : find(p[x]);
}

void merge(int a, int b) {
	a = p[a], b = p[b];
	if(a != b) {
		if(r[a] < r[b]) swap(a, b);
		r[a]++;
		p[b] = a;
	}
}

bool dfs(int u) {
	bool res = true;

	if(state[u] == 1) return false;
	else if(state[u] == 2) return true;

	state[u] = 1;
	for(int v : adj[u]) {
		res = (res && dfs(v));
	}
	state[u] = 2;

	return res;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
	cin >> n >> m;
	for(int i = 0; i < n; i++) p[i] = i;

	while(m--) {
		int u, v;
		char q;
		cin >> u >> q >> v;
		if(q == '=') {
			merge(u, v);
		}
		else {
			adj2.push_back({u, v});
		}
	}

	for(pair<int, int> e : adj2) {
		adj[p[e.first]].push_back(p[e.second]);
	}

	// for(int i = 0; i < n; i++) {
	// 	cout << i << " : ";
	// 	for(int j : adj[i]) {
	// 		cout << j << ' ';
	// 	}
	// 	cout << '\n';
	// }

	bool res = true;
	for(int i = 0; i < n; i++) {
		if(!state[p[i]]) res = (res && dfs(i));
	}

	cout << (res ? "consistent" : "inconsistent");

    return 0;
}