#include <iostream>
#include <cstring>
#include <vector>

#define N 10000

using namespace std;

int n, m;
int root[2 * (N + 1)];
vector<int> order, scc;
vector<int> adj[2 * (N + 1)], rev_adj[2 * (N + 1)];
bool visited[2 * (N + 1)];

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
    scc.push_back(u);

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
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v, nu, nv;
        cin >> u >> v;
        u *= 2, v *= 2;
        
        if(u > 0)
        {
            nu = u + 1;
        }
        else
        {
            nu = -u;
            u = -u + 1;
        }

        if(v > 0)
        {
            nv = v + 1;
        }
        else
        {
            nv = -v;
            v = -v + 1;
        }

        adj[nu].push_back(v);
        adj[nv].push_back(u);
        rev_adj[v].push_back(nu);
        rev_adj[u].push_back(nv);
    }

    for(int u = 2; u <= 2 * n; u++)
    {
        if(!visited[u])
        {
            dfs(u);
        }
    }

    memset(visited, false, sizeof(bool) * (2 * (n + 1)));
    for(auto u = order.rbegin(); u != order.rend(); u++)
    {
        if(!visited[*u])
        {
            scc.clear();

            rev_dfs(*u);

            for(int v : scc)
            {
                root[v] = *u;
            }
        }
    }

    bool solvable = true;
    for(int u = 2; u <= 2 * n; u += 2)
    {
        if(root[u] == root[u + 1])
        {
            solvable = false;
            break;
        }
    }
    cout << solvable;
    
    return 0;
}