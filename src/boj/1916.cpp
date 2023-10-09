#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, c[1001][1001];
    memset(c, -1, sizeof(c));

    cin >> n >> m;

    for (int u, v, x; m; m--) {
        cin >> u >> v >> x;
        c[u][v] = (c[u][v] == -1) ? x : min(c[u][v], x);
    }

    adj.resize(1001);
    for (int u = 1; u <= 1000; u++) {
        for (int v = 1; v <= 1000; v++) {
            if (c[u][v] != -1) {
                adj[u].push_back({v, c[u][v]});
            }
        }
    }

    int s, t;
    vector<int> d, p;

    cin >> s >> t;

    dijkstra(s, d, p);

    cout << d[t];

    return 0;
}
