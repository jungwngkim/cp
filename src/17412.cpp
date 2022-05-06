#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define N 401
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int s = 1, t = 2;
int c[N][N], f[N][N], level[N], work[N];
vector<int> adj[N];

bool bfs() {
    memset(level, -1, sizeof(level));
    level[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(level[v] == -1 && c[u][v] - f[u][v] > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[t] != -1;
}

int dfs(int u, int min_flow) {
    if(u == t) return min_flow;
    for(int &i = work[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(level[v] == level[u] + 1 && c[u][v] - f[u][v] > 0) {
            int flow = dfs(v, min(min_flow, c[u][v] - f[u][v]));
            if(flow > 0) {
                f[u][v] += flow;
                f[v][u] -= flow;
                return flow;
            }
        }
    }
    return 0;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = 1;
    }

    int ans = 0;
    while(bfs()) {
        memset(work, 0, sizeof(work));
        while(int pushed = dfs(s, INF)) {
            ans += pushed;
        }
    }
    cout << ans;
    
    return 0;
}