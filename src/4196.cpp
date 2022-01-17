#include <iostream>
#include <vector>
#include <cstring>

#define N 100000

using namespace std;

int n, m, root[N + 1], scc_indegree[N + 1];
vector<int> adj[N + 1], rev_adj[N + 1], order, component, root_nodes;
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

void dfs2(int u)
{
    component.push_back(u);

    visited[u] = true;

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            dfs2(v);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        for(int x = 1; x <= n; x++)
        {
            adj[x].clear();
            rev_adj[x].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);            
        }

        memset(visited, false, sizeof(bool) * (n + 1));
        order.clear();
        for(int u = 1; u <= n; u++)
        {
            if(!visited[u])
            {
                dfs1(u);
            }
        }

        memset(visited, false, sizeof(bool) * (n + 1));
        root_nodes.clear();
        for(auto u = order.begin(); u != order.end(); u++)
        {
            if(!visited[*u])
            {
                component.clear();

                dfs2(*u);
                for(int v : component)
                {
                    root[v] = *u;
                }
                root_nodes.push_back(*u);
            }
        }

        memset(scc_indegree, 0, sizeof(int) * (n + 1));
        for(int u = 1; u <= n; u++)
        {
            for(int v : adj[u])
            {
                if(root[u] != root[v])
                {
                    scc_indegree[root[v]]++;
                }
            }
        }
        
        int cnt = 0;
        for(int root_node : root_nodes)
        {
            cnt += !scc_indegree[root_node];
        }
        cout << cnt << '\n';
    }
    
    return 0;
}