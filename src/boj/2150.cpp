#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define N 10000

using namespace std;

int n, m;
vector<int> adj[N + 1], rev_adj[N + 1], order;
vector<vector<int>> scc;
bool visited[N + 1];

void dfs1(int u)
{
    visited[u] = true;

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }

    order.push_back(u);
}

void dfs2(int u, vector<int> &component)
{
    component.push_back(u);

    visited[u] = true;

    for(int v : rev_adj[u])
    {
        if(!visited[v])
        {
            dfs2(v, component);
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for(int u = 1; u <= n; u++)
    {
        if(!visited[u])
        {
            dfs1(u);
        }
    }

    memset(visited, false, sizeof(visited));
    
    for(auto u = order.rbegin(); u != order.rend(); u++)
    {
        if(!visited[*u])
        {
            vector<int> component;
            dfs2(*u, component);

            sort(component.begin(), component.end());
            scc.push_back(component);
        }
    }

    sort(scc.begin(), scc.end());

    cout << scc.size() << '\n';

    for(vector<int> component : scc)
    {
        for(int x : component)
        {
            cout << x << ' ';
        }
        cout << "-1\n";
    }
    
    return 0;
}