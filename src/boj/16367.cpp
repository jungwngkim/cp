#include <iostream>
#include <vector>
#include <cstring>

#define N 5000

using namespace std;

int n, m;
int order[2 * (N + 1)], order_idx;
int scc[2 * (N + 1)], scc_idx;
vector<int> adj[2 * (N + 1)], rev_adj[2 * (N + 1)];
bool visited[2 * (N + 1)], assignment[N + 1];

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
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    while(m--)
    {
        int u[3], nu[3];
        char c;

        for(int i = 0; i < 3; i++)
        {
            cin >> u[i] >> c;
            nu[i] = u[i] + n;
            if(c == 'R') swap(u[i], nu[i]);
        }

        for(int i = 0; i < 3; i++)
        {
            adj[nu[i]].push_back(u[(i + 1) % 3]);
            adj[nu[(i + 1) % 3]].push_back(u[i]);
            rev_adj[u[i]].push_back(nu[(i + 1) % 3]);
            rev_adj[u[(i + 1) % 3]].push_back(nu[i]);
        }
    }

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
        assignment[u] = scc[u] > scc[u + n];
    }
    
    if(solvable)
    {
        for(int u = 1; u <= n; u++)
        {
            cout << (assignment[u] ? 'B' : 'R');
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}