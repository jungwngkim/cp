#include <iostream>
#include <vector>
#include <cmath>

#define N 100000
#define K 17
#define INF 1000001

using namespace std;

typedef pair<int, int> pi;

int n, m, k;
vector<pi> adj[N + 1];

int up[N + 1][K + 1];
int tin[N + 1], tout[N + 1], timer;
pi len[N + 1][K + 1];

void dfs(int u, int p, int w)
{
    tin[u] = timer++;

    up[u][0] = p;
    len[u][0] = { w, w };
    if(u == 1) len[u][0] = { INF, 0 };
    for(int i = 1; i <= k; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
        len[u][i] = { 
            min(len[u][i - 1].first, len[up[u][i - 1]][i - 1].first), 
            max(len[u][i - 1].second, len[up[u][i - 1]][i - 1].second)
        };
    }

    for(pi edge : adj[u])
    {
        if(edge.first != p)
        {
            dfs(edge.first, u, edge.second);
        }
    }

    tout[u] = timer++;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

bool is_direct_ancestor(int u, int v)
{
    return tin[u] < tin[v] && tout[v] < tout[u];
}

pi calc_len(int u, int v)
{
    pi res = { INF, 0 };
    for(int i = k; i >= 0; i--)
    {
        if(up[v][i] && !is_direct_ancestor(up[v][i], u))
        {
            res = {
                min(res.first, len[v][i].first),
                max(res.second, len[v][i].second),                
            };
            v = up[v][i];
        }
    }
    return res;
}

int LCA(int u, int v)
{
    for(int i = k; i >= 0; i--)
    {
        if(up[u][i] && !is_direct_ancestor(up[u][i], v))
        {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    k = ceil(log2(n));

    dfs(1, 0, 0);

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        pi ans;
        if(is_ancestor(u, v))
        {
            ans = calc_len(u, v);
        }
        else if(is_ancestor(v, u))
        {
            ans = calc_len(v, u);
        }
        else
        {
            int x = LCA(u, v);
            pi ans1 = calc_len(x, u), ans2 = calc_len(x, v);
            ans = { 
                min(ans1.first, ans2.first),
                max(ans1.second, ans2.second)
            };
        }
        cout << ans.first << ' ' << ans.second << '\n';
    }
    
    return 0;
}