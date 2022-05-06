#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define N 801
#define INF 0x3f3f3f3f

using namespace std;

int n, m, ans;
int s = 401, t = 2;
int c[N][N], f[N][N], lv[N], wk[N];
vector<int> adj[N];

bool bfs() {
    memset(lv, -1, sizeof(lv));
    lv[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(lv[v] == -1 && c[u][v] - f[u][v] > 0) {
                lv[v] = lv[u] + 1;
                q.push(v);
            }
        }
    }

    return lv[t] != -1;
}

int dfs(int u, int fl) {
    if(u == t) {
        return fl;
    }

    for(int &i = wk[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(lv[v] == lv[u] + 1 && c[u][v] - f[u][v] > 0) {
            if(int new_fl = dfs(v, min(fl, c[u][v] - f[u][v]))) {
                f[u][v] += new_fl;
                f[v][u] -= new_fl;
                return new_fl;
            }
        }
    }

    return 0;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u + 400].push_back(v);
        adj[v].push_back(u + 400);
        adj[v + 400].push_back(u);
        adj[u].push_back(v + 400);
        c[u + 400][v] = c[v + 400][u] = 1;
    }

    for(int u = 1; u <= n; u++) {
        adj[u].push_back(u + 400);
        adj[u + 400].push_back(u);
        c[u][u + 400] = 1;
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << i << " : ";
    //     for(int v : adj[i]) {
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    // }

    // for(int i = 1 + 400; i <= n + 400; i++) {
    //     cout << i << " : ";
    //     for(int v : adj[i]) {
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    // }

    while(bfs()) {
        memset(wk, 0, sizeof(wk));
        while(int fl = dfs(s, INF)) {
            ans += fl;
        }
    }

    cout << ans;
    
    return 0;
}