#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define N 100001

int n, m;
vector<int> adj[N];
int in[N], out[N], timer;

class Fenwick {
    private:
        int s;
        vector<ll> fw;
    public:
        Fenwick(int _s) : s(_s), fw(_s + 1) {}

        void update(int pos, ll inc) {
            for (; pos <= s; pos += pos & -pos) {
                fw[pos] += inc;
            }
        }

        ll query(int pos) {
            ll res = 0;
            for (; pos > 0; pos -= pos & -pos) {
                res += fw[pos];
            }
            return res;
        }
};

void dfs(int u) {
    in[u] = ++timer;
    for (int v : adj[u]) {
        dfs(v);
    }
    out[u] = timer;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    int q, u;
    ll l, r;
    ll x;

    cin >> x;
    for (u = 2; u <= n; u++) {
        cin >> x;
        adj[x].push_back(u);
    }

    dfs(1);

    // for (u = 1; u <= n; u++) {
    //     printf("%d %d %d\n", u, in[u], out[u]);
    // }

    Fenwick f(n);
    while (m--) {
        cin >> q >> u;

        l = in[u], r = out[u];

        if (q == 1) {
            cin >> x;
            // printf("Update (%d, %d), inc %d\n", l, r, x);

            f.update(l, x);
            f.update(r + 1, -x);
        }
        else {
            cout << f.query(l) << '\n';
        }
    }

    return 0;
}

/*

7 2
-1 1 1 2 2 3 3
1 1 10
2 7
*/