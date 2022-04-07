#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001];
bool used[1001];

void dfs(int u)
{
    used[u] = true;

    for(int v : adj[u]) 
        if(!used[v])
            dfs(v);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int u, v; m--;) 
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int u = 1; u <= n; u++) 
        if(!used[u])
        {
            ans++;
            dfs(u);
        }

    cout << ans;

    return 0;
}