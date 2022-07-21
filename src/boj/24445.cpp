#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, src, tin[100001], timer;
vector<int> adj[100001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> src;
    for (int u, v; m; m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), [](const int &a, const int &b) { return a > b; });
    
    queue<int> q;
    q.push(src);
    tin[src] = ++timer;

    while(q.size()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(!tin[v]) {
                tin[v] = ++timer;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << tin[i] << '\n';

    return 0;
}