#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 802;

int n, m;
int s = 0, e = 801;
int c[N][N], f[N][N], w[N][N], p[N], d[N];
bool inq[N];
vector<int> adj[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int u = 1, v, vn; u <= n; u++) {
        cin >> vn;
        while (vn--) {
            cin >> v;
            v += 400;
            adj[u].push_back(v);
            adj[v].push_back(u);
            c[u][v] = 1;

            cin >> w[u][v];
            w[v][u] = -w[u][v];
        }
    }

    for (int u = 1; u <= n; u++) {
        adj[s].push_back(u);
        adj[u].push_back(s);
        c[s][u] = 1;
    }

    for (int v = 401; v <= 400 + m; v++) {
        adj[v].push_back(e);
        adj[e].push_back(v);
        c[v][e] = 1;
    }

    int max_flow = 0, min_cost = 0;
    while (true) {
        memset(p, -1, sizeof(p));
        memset(d, 0x3f, sizeof(d));
        memset(inq, false, sizeof(inq));
        queue<int> q;

        d[s] = 0;
        q.push(s);
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
        max_flow += fl;
    }

    cout << max_flow << '\n'
         << min_cost << '\n';

    return 0;
}