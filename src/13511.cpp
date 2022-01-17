#include <iostream>
#include <vector>
#include <cmath>

#define N 100000
#define K 17

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int n, m, k;
vector<pi> adj[N + 1];

int height[N + 1], parent[N + 1][K];
ll weight[N + 1][K];

int tin[N + 1], tout[N + 1], timer;

void dfs(int u, int p, int w, int h)
{
    tin[u] = timer++;

    parent[u][0] = p;
    weight[u][0] = w;
    height[u] = h;
    for(int i = 1; (1 << i) <= h; i++)
    {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
        weight[u][i] = weight[parent[u][i - 1]][i - 1] + weight[u][i - 1];
    }

    for(pi edge : adj[u])
    {
        if(edge.first != p)
        {
            dfs(edge.first, u, edge.second, h + 1);
        }
    }

    tout[u] = timer++;
}

inline bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    for(int i = k; i >= 0; i--)
    {
        if(parent[u][i] && !is_ancestor(parent[u][i], v))
        {
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

ll calc_weight(int a, int d)
{
    int h = height[d] - height[a];
    ll res = 0;
    for(int i = 0; i <= k; i++)
    {   
        if(h & (1 << i))
        {
            res += weight[d][i];
            d = parent[d][i];
        }
    }
    return res;
}

int calc_vertex(int a, int u, int v, int l)
{
    int hu = height[u] - height[a], hv = height[v] - height[a];
    if(hu == l) return a;
    else if(hu > l)
    {
        for(int i = 0; i <= k; i++)
        {   
            if(l & (1 << i))
            {
                u = parent[u][i];
            }
        }
        return u;
    }    
    else
    {
        l = hu + hv - l;
        for(int i = 0; i <= k; i++)
        {   
            if(l & (1 << i))
            {
                v = parent[v][i];
            }
        }
        return v;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    k = floor(log2(n));

    dfs(1, 0, 0, 0);

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int q, u, v, l, a;
        cin >> q >> u >> v;
        a = LCA(u, v);
        if(q == 1)
        {
            cout << calc_weight(a, u) + calc_weight(a, v) << '\n';
        }
        else
        {
            cin >> l;
            cout << calc_vertex(a, u, v, l - 1) << '\n'; 
        }
    }
    
    return 0;
}