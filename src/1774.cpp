#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int p[1001], s[1001];

void add(int x)
{
    p[x] = x;
    s[x] = 1;
}

int find(int x)
{
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    if(s[a] < s[b]) swap(a, b);
    p[b] = a;
    s[a] += s[b];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    pair<double, double> pos[1001];
    pair<double, pair<int, int>> adj[500500];

    for(int i = 1; i <= n; i++) cin >> pos[i].first >> pos[i].second;

    int k = 0;
    for(int i = 1; i < n; i++) 
        for(int j = i + 1; j <= n; j++)
            adj[k++] = {
                sqrt
                (
                    (pos[j].first - pos[i].first) * (pos[j].first - pos[i].first) +
                    (pos[j].second - pos[i].second) * (pos[j].second - pos[i].second)
                ),
                { i, j }
            };

    for(int i = 1; i <= n; i++) add(i);
    for(int i = 0; i < m; i++) 
    {
        int u, v; cin >> u >> v;
        u = find(u); v = find(v);
        if(u != v) merge(u, v);
    }

    sort(adj, adj + k);

    double sum = 0.0;
    int cnt = 1;
    for(int i = 0; cnt < n && i < k; i++)
    {
        double w = adj[i].first;
        int u = adj[i].second.first, v = adj[i].second.second;

        u = find(u); v = find(v);
        if(u != v)
        {
            merge(u, v);
            sum += w;
            cnt++;
        }
    }
    cout.precision(2);
    cout << fixed << sum;

    return 0;
}