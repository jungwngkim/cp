#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int p[101], size[101];

int find(int x)
{
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void create(int x)
{
    p[x] = x;
    size[x] = 1;
}

void merge(int a, int b)
{
    if(size[a] < size[b]) swap(a, b);
    p[b] = a;
    size[a] += size[b];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++) create(i);

    pair<double, double> pos[100];
    pair<double, pair<int, int>> adj[5050];

    for(int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;

    int m = 0;
    for(int i = 0; i < n - 1; i++) 
        for(int j = i + 1; j < n; j++) 
            adj[m++] = { 
                sqrt(
                    (pos[j].first - pos[i].first) * (pos[j].first - pos[i].first) + 
                    (pos[j].second - pos[i].second) * (pos[j].second - pos[i].second)
                ),
                { i, j } 
            };

    sort(adj, adj + m);

    double sum = 0.0;
    int cnt = 1;
    for(int i = 0; i < m; i++)
    {
        if(cnt == n) break;
        int u = adj[i].second.first, v = adj[i].second.second;
        double w = adj[i].first;

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