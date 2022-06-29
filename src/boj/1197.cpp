#include <iostream>
#include <algorithm>

using namespace std;

pair<int, pair<int, int>> adj[100000];
int p[10001], size[10001];

void add(int x)
{
    p[x] = x; 
    size[x] = 1;
}

int find(int x)
{
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
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

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) add(i);
    for(int i = 0; i < m; i++) cin >> adj[i].second.first >> adj[i].second.second >> adj[i].first;

    sort(adj, adj + m);

    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++)
    {
        if(cnt == n) break;

        int u = adj[i].second.first, v = adj[i].second.second, w = adj[i].first;
        u = find(u); v = find(v);
        
        if(u != v)
        {
            merge(u, v);
            ans += w;
            cnt++;
        }
    }
    cout << ans;

    return 0;
}