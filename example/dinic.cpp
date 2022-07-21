int s, t;
int c[N][N], f[N][N], lv[N], wk[N];
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

int calc() {
	int ans = 0;
    while(bfs()) {
        memset(wk, 0, sizeof(wk));
        while(int fl = dfs(s, INF)) {
            ans += fl;
        }
    }
    cout << ans;
}