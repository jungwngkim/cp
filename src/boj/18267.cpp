#include <iostream>
#include <vector>

#define N 100001

using namespace std;

int n, m;
char breed[N];
int comp[N];
vector<int> adj[N];

void dfs(int u, int idx_comp)
{
    comp[u] = idx_comp;

    for(int v : adj[u])
        if(!comp[v] && breed[u] == breed[v])
            dfs(v, idx_comp);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> breed[i];

    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int u = 1; u <= n; u++)
        if(!comp[u])
            dfs(u, u);

    for(int i = 0; i < m; i++)
    {
        char c;
        int u, v;
        cin >> u >> v >> c;

        if(comp[u] != comp[v]) cout << 1;
        else
        {
            if(breed[u] == c) cout << 1;
            else cout << 0;
        }
    }

    return 0;
}