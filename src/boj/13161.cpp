#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define N 502
#define INF 0x3f3f3f3f

using namespace std;

int n, ans;
int s = 0, t = 501;
int c[N][N], f[N][N], lv[N], wk[N], ck[N];
vector<int> adj[N];

bool bfs() {
    queue<int> q;
    q.push(s);

    memset(lv, -1, sizeof(lv));
    lv[s] = 0;

    while(q.size()) {
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

void calc() {
    queue<int> q;
    q.push(s);
    
    ck[s] = 1;

    while(q.size()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(!ck[v] && c[u][v] - f[u][v] > 0) {
                ck[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int u = 1, b; u <= n; u++) {
        cin >> b;
        if(b == 1) {
            adj[u].push_back(s);
            adj[s].push_back(u);
            c[s][u] = INF;
        }
        if(b == 2) {
            adj[u].push_back(t);
            adj[t].push_back(u);
            c[u][t] = INF;
        }

        for(int v = u + 1; v <= n; v++) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for(int u = 1; u <= n; u++) for(int v = 1; v <= n; v++) {
        cin >> c[u][v];
    }

    while(bfs()) {
        memset(wk, 0, sizeof(wk));
        while(int fl = dfs(s, INF)) {
            ans += fl;
        }
    }
    
    cout << ans << '\n';
    
    calc();
    for(int u = 1; u <= n; u++) {
        if(ck[u]) cout << u << ' ';
    }
    cout << '\n';
    for(int u = 1; u <= n; u++) {
        if(!ck[u]) cout << u << ' ';
    }
    cout << '\n';

    return 0;
}