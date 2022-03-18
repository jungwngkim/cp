#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define N 1001

using namespace std;

typedef pair<int, int> pi;

int n, m, s;
int t[N], rev_t[N];
vector<pi> adj[N], rev_adj[N];

void dijkstra()
{
    priority_queue<pi> q;
    q.push({ 0, s });

    memset(t, 0x3f, sizeof(t));
    t[s] = 0;

    while(!q.empty())
    {
        int u = q.top().second, t_u = -q.top().first;
        q.pop();

        if(t[u] != t_u) continue;

        for(pi e : adj[u])
        {
            int v = e.first, t_uv = e.second;
            if(t[v] > t_u + t_uv)
            {
                t[v] = t_u + t_uv;
                q.push({ -t[v], v });
            }
        }
    }
}

void rev_dijkstra()
{
    priority_queue<pi> q;
    q.push({ 0, s });

    memset(rev_t, 0x3f, sizeof(rev_t));
    rev_t[s] = 0;

    while(!q.empty())
    {
        int u = q.top().second, t_u = -q.top().first;
        q.pop();

        if(rev_t[u] != t_u) continue;

        for(pi e : rev_adj[u])
        {
            int v = e.first, t_uv = e.second;
            if(rev_t[v] > t_u + t_uv)
            {
                rev_t[v] = t_u + t_uv;
                q.push({ -rev_t[v], v });
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> s;

    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        rev_adj[v].push_back({ u, w });
    }

    dijkstra();
    rev_dijkstra();

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, t[i] + rev_t[i]);
    }
    cout << ans;
    
    return 0;
}