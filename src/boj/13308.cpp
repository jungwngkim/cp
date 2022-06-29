#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define N 2501

using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int>> pii;
typedef pair<int, int> pi;

int n, m;
int p[N];
ll d[N][N];
vector<pi> adj[N];

void dijk()
{
    memset(d, 0x3f, sizeof(d));
    d[1][p[1]] = 0;

    priority_queue<pii> q;
    q.push({ 0, { 1, p[1] } });

    while(!q.empty())
    {
        ll d_u = -q.top().first;
        int u = q.top().second.first, p_u = q.top().second.second;
        q.pop();

        if(d[u][p_u] < d_u) continue;

        for(pi e : adj[u])
        {
            int v = e.first, d_uv = e.second;
            if(d[v][p_u] > d_u + d_uv * p_u)
            {
                d[v][p_u] = d_u + d_uv * p_u;
                q.push({ -d[v][p_u], { v, min(p_u, p[v]) } });
            }
        }
    }
}


int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];

    for(int u, v, w; m--;)
    {
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijk();
    
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 0; i < N; i++) ans = min(ans, d[n][i]);
    cout << ans;
    return 0;
}