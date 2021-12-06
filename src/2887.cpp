#include <iostream>
#include <algorithm>

using namespace std;

struct Point { int x, y, z, idx; };
Point point[100000];

pair<int, pair<int, int>> adj[300000];

int p[100000], s[100000];
void add(int x) 
{
    p[x] = x; s[x] = 1;
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
    int n; cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> point[i].x >> point[i].y >> point[i].z;
        point[i].idx = i;
    }

    int m = 0;
    sort(point, point + n, [](const Point &a, const Point &b) { return a.x < b.x; });
    for(int i = 0; i < n - 1; i++) 
        adj[m++] = { point[i + 1].x - point[i].x, { point[i + 1].idx, point[i].idx } };

    sort(point, point + n, [](const Point &a, const Point &b) { return a.y < b.y; });
    for(int i = 0; i < n - 1; i++) 
        adj[m++] = { point[i + 1].y - point[i].y, { point[i + 1].idx, point[i].idx } };

    sort(point, point + n, [](const Point &a, const Point &b) { return a.z < b.z; });
    for(int i = 0; i < n - 1; i++) 
        adj[m++] = { point[i + 1].z - point[i].z, { point[i + 1].idx, point[i].idx } };

    sort(adj, adj + m);

    for(int i = 0; i < n; i++) add(i);

    long long sum = 0;
    int cnt = 1;
    for(int i = 0; cnt < n && i < m; i++)
    {
        int w = adj[i].first;
        int u = adj[i].second.first, v = adj[i].second.second;

        u = find(u); v = find(v);
        if(u != v)
        {
            merge(u, v);
            sum += w;
            cnt++;
        }
    }
    cout << sum << '\n';

    return 0;
}