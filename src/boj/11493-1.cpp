#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f, N = 502;

int t, n, m;
const int s = 0, e = 501;
int c[N][N], f[N][N], w[N][N], p[N], d[N];
bool inq[N];
vector<int> adj[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));
        for (int i = 0; i < N; i++) adj[i].clear();

        cin >> n >> m;
        for (int u, v; m; m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            c[u][v] = c[v][u] = inf;
            w[u][v] = w[v][u] = 1;
        }

        for (int x = 1, t; x <= n; x++) {
            cin >> t;
            if (!t) {
                adj[s].push_back(x);
                adj[x].push_back(s);
                c[s][x] = 1;
            }
        }

        for (int x = 1, t; x <= n; x++) {
            cin >> t;
            if (!t) {
                adj[e].push_back(x);
                adj[x].push_back(e);
                c[x][e] = 1;
            }
        }

        int min_cost = 0;
        while (true) {
            memset(p, -1, sizeof(p));
            memset(d, 0x3f, sizeof(d));
            memset(inq, false, sizeof(inq));

            queue<int> q;
            q.push(s);
            d[s] = 0;
            inq[s] = true;

            while (q.size()) {
                int u = q.front();
                q.pop();

                inq[u] = false;

                for (int v : adj[u]) {
                    if (c[u][v] - f[u][v] > 0 && d[v] > d[u] + w[u][v]) {
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                        if (!inq[v]) {
                            q.push(v);
                            inq[v] = true;
                        }
                    }
                }
            }

            if (p[e] == -1) break;

            int fl = inf;
            for (int x = e; x != s; x = p[x]) fl = min(fl, c[p[x]][x] - f[p[x]][x]);
            for (int x = e; x != s; x = p[x]) {
                min_cost += fl * w[p[x]][x];
                f[p[x]][x] += fl;
                f[x][p[x]] -= fl;
            }
        }
        cout << min_cost << '\n';
    }

    return 0;
}