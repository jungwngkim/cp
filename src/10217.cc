#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, pair<int, int>> I3;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<I3>> adj(n+1);
        for(int i = 0; i < k; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].push_back({v, {c, d}});
        }

        int d[101][10001];
        memset(d, 0x3f, sizeof(d));
        d[1][0] = 0;

        priority_queue<I3, vector<I3>, greater<I3>> pq;
        pq.push({0, {1, 0}});

        while(!pq.empty()) {
            int d_u = pq.top().first;
            int u = pq.top().second.first;
            int c_u = pq.top().second.second;

            pq.pop();

            if(d_u != d[u][c_u]) continue;

            for(I3 edge : adj[u]) {
                int v = edge.first;
                int c_v = c_u + edge.second.first;
                int d_v = d_u + edge.second.second;

                if(c_v > m) continue;

                if(d_v < d[v][c_v]) {
                    d[v][c_v] = d_v;
                    for(int i = c_v + 1; i <= m; i++) {
                        if(d[v][i] <= d_v) break;
                        d[v][i] = d_v;
                    }
                    pq.push({d_v, {v, c_v}});
                }
            }
        }

        int ans = INF;
        for(int i = 1; i <= m; i++) ans = min(ans, d[n][i]);
        if(ans == INF) cout << "Poor KCM\n";
        else cout << ans << '\n';
    }
    return 0;
}