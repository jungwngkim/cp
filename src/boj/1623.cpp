#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, w[200001], dp1[200001], dp2[200001];
bool ans[200001];
vector<int> adj[200001];

void calc(int v) {
    for (int u : adj[v]) calc(u);

    int d1 = 0, d2 = 0;
    for (int u : adj[v]) d1 += max(0, dp2[u]);
    for (int u : adj[v]) d2 += max(0, max(dp1[u], dp2[u]));

    dp1[v] = w[v] + d1;
    dp2[v] = d2;
}

void find(int v, bool used) {
    ans[v] = used;

    if (used) {
        for (int u : adj[v]) 
            if (dp2[v] > 0)
                find(u, false);
    }
    else {
        for (int u : adj[v]) {
            if (max(dp1[u], dp2[u]) <= 0) continue;
            find(u, dp1[u] >= dp2[u]);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        adj[p].push_back(i);
    }

    calc(1);

    cout << dp1[1] << ' ' << dp2[1] << '\n';

    find(1, true);
    for (int i = 1; i <= n; i++) 
        if (ans[i])
            cout << i << ' ';
    cout << -1 << '\n';

    memset(ans, false, sizeof(ans));
    find(1, false);
    for (int i = 1; i <= n; i++) 
        if (ans[i])
            cout << i << ' ';
    cout << -1 << '\n';


    return 0;
}