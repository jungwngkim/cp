#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define N 2003
#define INF 0x3f3f3f3f

using namespace std;

int n, m, k;
int s = 0, t = 2001, b = 2002;
int c[N][N], f[N][N], lv[N], wk[N];
int ans = 0;
vector<int> adj[N];

bool bfs() {
    queue<int> q;
    q.push(s);

    memset(lv, -1, sizeof(lv));
    lv[s] = 0;

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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    adj[s].push_back(b);
    adj[b].push_back(s);
    c[s][b] = k;

    for(int u = 1; u <= n; u++) {
        adj[s].push_back(u);
        adj[u].push_back(s);
        c[s][u] = 1;

        adj[b].push_back(u);
        adj[u].push_back(b);
        c[b][u] = k;
    }

    for(int v = 1001; v <= m + 1000; v++) {
        adj[v].push_back(t);
        adj[t].push_back(v);
        c[v][t] = 1;
    }

    for(int u = 1, vn; u <= n; u++)
    {
        cin >> vn;
        adj[u].resize(vn);
        for (int &v : adj[u]) {
            cin >> v;
            v += 1000;
            adj[v].push_back(u);

            c[u][v] = 1;
        }
    }

    while(bfs()) {
        memset(wk, 0, sizeof(wk));
        while(int fl = dfs(s, INF)) {
            ans += fl;
        }
    }

    cout << ans;

    return 0;
}