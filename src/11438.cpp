#include <iostream>
#include <vector>
#include <cmath>

#define N 100000
#define K 17

using namespace std;

int n, m, k, tin[N + 1], tout[N + 1], timer, up[N + 1][K + 1];
vector<int> adj[N + 1];

void dfs(int u, int p)
{
    tin[u] = timer++;

    up[u][0] = p;
    for(int i = 1; i <= k; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for(int v : adj[u])
    {
        if(v != p)
        {
            dfs(v, u);
        }
    }

    tout[u] = timer++;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    for(int i = k; i >= 0; i--)
    {
        if(!is_ancestor(up[u][i], v))
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    k = ceil(log2(n));
    dfs(1, 1);

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
    
    return 0;
}