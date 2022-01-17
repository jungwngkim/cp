#include <iostream>
#include <cstring>
#include <vector>

#define N 10000

using namespace std;

int n, m;
int scc[2 * N + 1], scc_idx;
vector<int> order;
vector<int> adj[2 * N + 1], rev_adj[2 * N + 1];
bool assignment[N + 1], visited[2 * N + 1];

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

    order.push_back(u);
}

void rev_dfs(int u)
{
    visited[u] = true;
    scc[u] = scc_idx;

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

    cin >> n >> m;
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

        adj[nu].push_back(v);
        adj[nv].push_back(u);
        rev_adj[u].push_back(nv);
        rev_adj[v].push_back(nu);
    }

    for(int u = 1; u <= 2 * n; u++)
    {
        if(!visited[u])
        {
            dfs(u);
        }
    }

    memset(visited, false, sizeof(bool) * (2 * n + 1));
    for(auto u = order.rbegin(); u != order.rend(); u++)
    {
        if(!visited[*u])
        {
            scc_idx++;
            rev_dfs(*u);
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
        assignment[u] = scc[u] > scc[u + n];
    }

    cout << solvable << '\n';
    if(solvable)
    {
        for(int u = 1; u <= n; u++)
        {
            cout << assignment[u] << ' ';
        }
    }

    return 0;
}