#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, src, tin[100001], timer;
vector<int> adj[100001];

void dfs(int u) {
    tin[u] = ++timer;

    for (int v : adj[u]) {
        if (!tin[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> src;
    for (int u, v; m; m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    dfs(src);
    for (int i = 1; i <= n; i++) cout << tin[i] << '\n';

    return 0;
}