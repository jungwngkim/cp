#include <iostream>
#include <vector>

using namespace std;

struct Event {
    int u, v;
    bool used;
};

int n, m, q, e, x[500000], ans[500000];
Event ev[500000];

int p[200000], s[200000], c[200000], r[200000];

int find(int a) {
    return p[a] == a ? a : find(p[a]);
}

int merge(int a, int b) {
    int res = 0;
    a = find(a), b = find(b);
    if (a != b) {
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        r[a]++;
        if (c[a] == 1 && c[b] == 0) {
            c[b] = 1;
            res = s[b];
        }
        if (c[a] == 0 && c[b] == 1) {
            c[a] = 1;
            res = s[a];
        }
        s[a] += s[b];
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> e;

    for (int i = 0; i < n; i++) {
        p[i] = i;
        s[i] = 1;
    }
    for (int i = n; i < n + m; i++) {
        p[i] = i;
        c[i] = 1;
    }

    for (int i = 0; i < e; i++) {
        cin >> ev[i].u >> ev[i].v;
        ev[i].u--, ev[i].v--;
        ev[i].used = true;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x[i];
        x[i]--;
        ev[x[i]].used = false;
    }

    for (int i = 0; i < e; i++) {
        if (ev[i].used) {
            ans[q - 1] += merge(ev[i].u, ev[i].v);
        }
    }

    for (int i = q - 1; i > 0; i--) {
        ans[i - 1] = merge(ev[x[i]].u, ev[x[i]].v) + ans[i];
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}