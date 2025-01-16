#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
vector<int> adj[10];
bool visited[10];
ll val[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void mul(int v, ll c) {
    visited[v] = true;
    val[v] *= c;

    for (int u : adj[v]) {
        if (visited[u]) continue;
        mul(u, c);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll a, b, p, q;
        cin >> a >> b >> p >> q;

        ll val_a = val[b] * p, val_b = val[a] * q;

        ll g = gcd(val_a, val_b);

        memset(visited, 0, sizeof(visited));
        mul(a, val_a / g);
        mul(b, val_b / g);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) cout << val[i] << ' ';

    return 0;
}

