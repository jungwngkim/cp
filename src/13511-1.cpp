#include <iostream>
#include <cmath>
#include <vector>

#define N 100000
#define K 17

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int n, m;
vector<pi> adj[N + 1];

int height[N + 1], parent[N + 1][K];
ll weight[N + 1][K];

int tin[N + 1], tout[N + 1], timer;

// pi euler[2 * N - 1][K + 1];
// int euler_idx[N + 1], idx, lg[2 * N];

void dfs(int u, int p, ll w, int h)
{
    tin[u] = timer++;

    height[u] = h;
    parent[u][0] = p;
    weight[u][0] = w;

    // cout << u << p << w << h << '\n';

    for(int i = 1; i < K; i++)
    {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
        weight[u][i] = weight[parent[u][i - 1]][i - 1] + weight[u][i - 1];
    }

    // euler[idx][0] = { h, u };
    // euler_idx[u] = idx;
    // idx++;

    for(pi edge : adj[u])
    {
        if(edge.first != p)
        {
            dfs(edge.first, u, edge.second, h + 1);
            // euler[idx][0] = { h, u };
            // idx++;
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
    for(int i = K; i >= 0; i--)
    {
        
    }
}

// int LCA(int u, int v)
// {
//     u = euler_idx[u], v = euler_idx[v];
//     if(u > v) swap(u, v);

//     int j = lg[v - u + 1];
//     return min(euler[u][j], euler[v - (1 << j) + 1][j]).second;
// }

// ll calc_weight(int a, int d)
// {
//     ll res = 0;
//     int h = height[d] - height[a];
//     for(int i = 0; i < K; i++)
//     {
//         if(h & (1 << i))
//         {
//             res += weight[d][i];
//             d = parent[d][i];
//         }
//     }
//     // cout << a << ' ' << d << ' ' << res << '\n';
//     return res;
// }

// int calc_vertex(int u, int v, int a, int l)
// { 
//     int hu = height[u] - height[a], hv = height[v] - height[a];
//     // cout << u << ' ' << v << ' ' << a << ' ' << l << ' ' << hu << ' ' << hv << '\n';
//     if(hu == l) return a;
//     else if(hu > l)
//     {
//         for(int i = 0; i < K; i++)
//         {
//             if(l & (1 << i))
//             {
//                 u = parent[u][i];
//             }
//         }
//         return u;
//     }
//     else
//     {
//         l = hu + hv - l;
//         for(int i = 0; i < K; i++)
//         {
//             if(l & (1 << i))
//             {
//                 v = parent[v][i];
//             }
//         }
//         return v;
//     }
// }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // cin.tie(0); cout.tie(0);
    // ios_base::sync_with_stdio(0);

    cout << "Program Started\n";

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    cout << "Data Inputted\n";

    dfs(1, -1, 0, 0);
    
    return 0;
    // lg[1] = 0;
    // for(int i = 2; i < 2 * n; i++)
    // {
    //     lg[i] = lg[i / 2] + 1;
    // }
    
    // build rmq
    // for(int j = 1; j <= K; j++)
    // {
    //     for(int i = 0; i + (1 << j) <= 2 * n - 1; i++)
    //     {
    //         euler[i][j] = min(euler[i][j - 1], euler[i + (1 << (j - 1))][j - 1]);
    //     }
    // }

    // for(int j = 0; j < K; j++)
    // {
    //     for(int i = 1; i <= n; i++)
    //     {
    //         cout << "(" << parent[i][j] << ", " << weight[i][j] << ") ";
    //     }
    //     cout << '\n';
    // }

    // for(int j = 0; j <= euler_k; j++)
    // {
    //     for(int i = 0; i < 2 * n - 1; i++)
    //     {
    //         cout << "(" << euler[i][j].first << ", " << euler[i][j].second << ") ";
    //     }
    //     cout << '\n';
    // }

    // cin >> m;
    // for(int i = 0; i < m; i++)
    // {
    //     int q, u, v, l, a;
    //     cin >> q >> u >> v;

    //     a = LCA(u, v);
    //     // cout << u << ' ' << v << ' ' << a << '\n';
    //     if(q == 1)
    //     {
    //         cout << calc_weight(a, u) + calc_weight(a, v) << '\n';
    //     }
    //     else 
    //     {
    //         cin >> l;
    //         cout << calc_vertex(u, v, a, l - 1) << '\n';
    //     }
    // }
    
    // return 0;
}