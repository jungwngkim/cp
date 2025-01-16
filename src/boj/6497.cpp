/*
algorithm: Minimum Spanning Tree
*/

#include <algorithm>
#include <iostream>

using namespace std;

struct Edge {
    int w, u, v;
};

int n, m, S, s;
Edge e[200000];

int p[200000], r[200000];

int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    r[a]++;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        S = s = 0;
        for (int x = 0; x < n; x++) {
            p[x] = x;
            r[x] = 0;
        }

        for (int i = 0; i < m; i++) {
            cin >> e[i].u >> e[i].v >> e[i].w;
            S += e[i].w;
        }

        sort(e, e + m, [](const Edge &a, const Edge &b) { return a.w < b.w; });

        for (int i = 0; i < m; i++) {
            if (find(e[i].u) == find(e[i].v)) continue;
            s += e[i].w;
            merge(e[i].u, e[i].v);
        }

        cout << S - s << '\n';
    }

    return 0;
}