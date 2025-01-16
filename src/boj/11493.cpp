#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edg {
    int v, c, r, w;
};
const int inf = 0x3f3f3f3f, N = 502;

int t, n, m;
const int src = 0, snk = 501;
int pa[N], pe[N], d[N];
bool inq[N];
vector<edg> adj[N];

void add_edge(int u, int v, int c, int w) {
    adj[u].push_back({v, c, (int)adj[v].size(), w});
    adj[v].push_back({u, 0, (int)adj[u].size() - 1, -w});
}

bool spfa() {
    bool ok = false;
    memset(d, 0x3f, sizeof(d));
    memset(inq, false, sizeof(inq));

    queue<int> q;
    q.push(src);
    d[src] = 0;
    inq[src] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u == snk) ok = true;
        inq[u] = false;

        for (int i = 0; i < adj[u].size(); i++) {
            edg e = adj[u][i];
            if (e.c > 0 && d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                pa[e.v] = u;
                pe[e.v] = i;
                if (!inq[e.v]) {
                    q.push(e.v);
                    inq[e.v] = true;
                }
            }
        }
    }

    return ok;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        for (int i = 0; i < N; i++) adj[i].clear();

        cin >> n >> m;
        for (int u, v; m; m--) {
            cin >> u >> v;
            add_edge(u, v, inf, 1);
            add_edge(v, u, inf, 1);
        }

        for (int x = 1, t; x <= n; x++) {
            cin >> t;
            if (!t) add_edge(x, snk, 1, 0);
        }

        for (int x = 1, t; x <= n; x++) {
            cin >> t;
            if (!t) add_edge(src, x, 1, 0);
        }

        int min_cost = 0;
        while (spfa()) {
            int fl = inf;
            for (int x = snk; x != src; x = pa[x]) fl = min(fl, adj[pa[x]][pe[x]].c);
            min_cost += d[snk] * fl;
            for (int x = snk; x != src; x = pa[x]) {
                int r = adj[pa[x]][pe[x]].r;
                adj[x][r].c += fl;
                adj[pa[x]][pe[x]].c -= fl;
            }
        }
        cout << min_cost << '\n';
    }

    return 0;
}