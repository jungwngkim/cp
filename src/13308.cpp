#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define N 2501

using namespace std;

typedef pair<int, pair<int, int>> pii;
typedef pair<int, int> pi;

int n, m;
int p[N], d[N];
vector<pi> adj[N];

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;

    priority_queue<pii> q;
    q.push({ 0, { 1, p[1] } });

    while(!q.empty())
    {
        int d_u = -q.top().first, u = q.top().second.first, p_u = q.top().second.second;
        q.pop();

        if(d[u] != d_u) continue;

        for(pi e : adj[u])
        {
            int v = e.first, d_uv = e.second;
            if(d[v] > d_u + d_uv * p_u)
            {
                d[v] = d_u + d_uv * p_u;
                cout << u << '>' << v << ' ' << d[v] << '\n';
                q.push({ -d[v], { v, min(p_u, p[v]) } });
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];

    for(int u, v, w; m--;)
    {
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra();

    cout << d[n];
    
    return 0;
}