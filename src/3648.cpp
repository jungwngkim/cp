#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define N 1000

using namespace std;

int n, m;
int scc[2 * N], scc_idx;
int order[2 * N], order_idx;
vector<int> adj[2 * N], rev_adj[2 * N];
bool visited[2 * N];

void dfs(int u)
{
    visited[u] = true;

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }

    order[++order_idx] = u;
}

void rev_dfs(int u)
{
    scc[u] = scc_idx;

    visited[u] = true;

    for(int v : rev_adj[u])
    {
        if(!visited[v])
        {
            rev_dfs(v);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m)
    {
        for(int u = 1; u <= 2 * n; u++)
        {
            adj[u].clear();
            rev_adj[u].clear();
        }
        scc_idx = order_idx = 0;

        for(int i = 0; i < m; i++)
        {
            int u, v, nu, nv;
            cin >> u >> v;

            if(u > 0)
            {
                nu = u + n;
            }
            else
            {
                nu = -u;
                u = -u + n;
            }

            if(v > 0)
            {
                nv = v + n;
            }
            else
            {
                nv = -v;
                v = -v + n;
            }

            adj[nu].emplace_back(v);
            adj[nv].emplace_back(u);
            rev_adj[u].emplace_back(nv);
            rev_adj[v].emplace_back(nu);
        }
    
        memset(visited, false, sizeof(visited));
        for(int u = 1; u <= 2 * n; u++)
        {
            if(!visited[u])
            {
                dfs(u);
            }
        }

        memset(visited, false, sizeof(visited));
        for(int i = 2 * n; i >= 1; i--)
        {
            int u = order[i];
            if(!visited[u])
            {
                scc_idx++;
                rev_dfs(u);
            }
        }

        bool solvable = true;
        for(int u = 1; u <= n; u++)
        {
            if(scc[u] == scc[u + n])
            {
                solvable = false;
                break;
            }
        }

        cout << (solvable && scc[1] > scc[1 + n] ? "yes\n" : "no\n");
    }
    
    
    return 0;
}