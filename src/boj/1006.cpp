#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define N 20000

using namespace std;

int t, n, w, m[N], deg[N];
bool used[N];
vector<int> adj[N];
queue<int> q[4];

void insert(int i, int j) {
    if (m[i] + m[j] <= w) {
        adj[i].push_back(j);
        adj[j].push_back(i);
        deg[i]++;
        deg[j]++;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n >> w;

        memset(deg, 0, sizeof(deg));

        for (int i = 0; i < 2 * n; i++) {
            cin >> m[i];
            adj[i].clear();
        }

        if (n > 2) {
            insert(0, n - 1);
            insert(n, 2 * n - 1);
        }
        for (int i = 0; i < n - 1; i++) insert(i, i + 1);
        for (int i = 0; i < n; i++) insert(i, i + n);
        for (int i = n; i < 2 * n - 1; i++) insert(i, i + 1);

        for (int i = 0; i < 2 * n; i++) {
            if (deg[i] > 0) q[deg[i]].push(i);
        }

        memset(used, false, sizeof(used));
        int ans = 0;
        while (!q[1].empty() || !q[2].empty() || !q[3].empty()) {
            int d = 1, v;

            while (q[d].empty()) d++;
            v = q[d].front();
            q[d].pop();

            if (used[v] || d != deg[v]) continue;

            int u = -1;
            for (int x : adj[v]) {
                if (used[x]) continue;
                if (u == -1) u = x;
                if (deg[x] < deg[u]) u = x;
            }
            if (u == -1) continue;
            
            used[v] = used[u] = true;

            for (int x : adj[v]) {
                deg[x]--;
                if (!used[x] && deg[x] > 0) q[deg[x]].push(x);
            }

            for (int x : adj[u]) {
                deg[x]--;
                if (!used[x] && deg[x] > 0) q[deg[x]].push(x);
            }

            ans++;
        }

        cout << 2 * n - ans << '\n';
    }

    return 0;
}
