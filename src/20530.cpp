#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, q;
vector<int> adj[200001];

int parent[200001], visit[200001];
vector<int> cycle;

void dfs1(int u, int p)
{
    if(visit[u] == 1)
    {
        cycle.push_back(u);

        int x = p;
        while(x != u)
        {
            cycle.push_back(x);
            x = parent[x];
        }

        return;
    }
    parent[u] = p;
    visit[u] = 1;

    for(int v : adj[u])
        if(v != p && visit[v] != 2)
            dfs1(v, u);

    visit[u] = 2;
}

void dfs2(int u, int p, int idx)
{
    parent[u] = idx;

    for(int v : adj[u])
        if(v != p && !parent[v])
            dfs2(v, u, idx);
}

void build()
{
    dfs1(1, -1);

    memset(parent, 0, sizeof(parent));
    for(int x : cycle) parent[x] = x;
    for(int x : cycle) dfs2(x, -1, x);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for(int i = 0, u, v; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build();

    for(int i = 0, u, v; i < q; i++)
    {
        cin >> u >> v;
        cout << (parent[u] == parent[v] ? 1 : 2) << '\n';
    }
    
    return 0;
}