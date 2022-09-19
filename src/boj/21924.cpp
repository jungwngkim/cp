/*
algorithm: Minimum Spanning Tree
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int w, u, v;
};

long long S, s;
int n, m;
Edge e[500000];

int p[500000], r[500000], cnt;

int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    r[a]++;
    cnt--;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int x = 1; x <= n; x++) p[x] = x;
    cnt = n;

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

    if (cnt > 1)
        cout << -1;
    else
        cout << S - s;

    return 0;
}