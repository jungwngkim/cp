#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define N 100000

using namespace std;

int n, m;
int root[N], scc_indegree[N];
vector<int> order, component, root_nodes;
vector<int> adj[N], rev_adj[N], components[N];
bool visited[N];

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

    for(int v : rev_adj[u])
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

        for(int x = 0; x < n; x++)
        {
            adj[x].clear();
            rev_adj[x].clear();
            components[x].clear();
        }
        order.clear();
        root_nodes.clear();
        memset(scc_indegree, 0, sizeof(int) * n);
        
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        memset(visited, false, sizeof(bool) * n);
        for(int u = 0; u < n; u++)
        {
            if(!visited[u])
            {
                dfs1(u);
            }
        }

        memset(visited, false, sizeof(bool) * n);
        for(auto u = order.rbegin(); u != order.rend(); u++)
        {
            if(!visited[*u])
            {
                component.clear();

                dfs2(*u);
                sort(component.begin(), component.end());
                for(int x : component)
                {
                    root[x] = *u;
                }
                root_nodes.push_back(*u);
                components[*u] = component;
            }
        }

        for(int u = 0; u < n; u++)
        {
            for(int v : adj[u])
            {
                int root_u = root[u], root_v = root[v];

                if(root_u != root_v)
                {
                    scc_indegree[root_v]++;
                }
            }
        }

        int cnt = 0, root_scc;
        for(int root_node : root_nodes)
        {
            if(!scc_indegree[root_node])
            {
                cnt++;
                root_scc = root_node;
            }
        }

        if(cnt == 1)
        {
            for(int x : components[root_scc])
            {
                cout << x << '\n';
            }
        }
        else
        {
            cout << "Confused\n";
        }
        cout << '\n';
    }
    
    return 0;
}