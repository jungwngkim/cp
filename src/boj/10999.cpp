#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1000001;

int n, m, k;
ll fw_a[N], fw_b[N];

void update_a(int pos, ll inc) {
    for (; pos <= n; pos += pos & -pos) {
        fw_a[pos] += inc;
    }
}

ll query_a(int pos) {
    ll res = 0;
    for (; pos > 0; pos -= pos & -pos) {
        res += fw_a[pos];
    }
    return res;
}

void update_b(int pos, ll inc) {
    for (; pos <= n; pos += pos & -pos) {
        fw_b[pos] += inc;
    }
}

ll query_b(int pos) {
    ll res = 0;
    for (; pos > 0; pos -= pos & -pos) {
        res += fw_b[pos];
    }
    return res;
}

void update(int l, int r, ll inc) {
    update_a(l, inc);
    update_a(r + 1, -inc);

    update_b(l, -(l - 1) * inc);
    update_b(r + 1, r * inc);
}

ll query(ll i) {
    return query_a(i) * i + query_b(i);
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << query(i) << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    m += k;

    ll q, l, r, x;
    for (int i = 1; i <= n; i++) {
        cin >> q;
        update(i, i, q);
    }

    // print();

    while (m--) {
        cin >> q >> l >> r;
        if (q == 1) {
            cin >> x;
            update(l, r, x);
        }
        else {
            cout << query(r) - query(l - 1) << '\n';
        }
    }

    return 0;
}
