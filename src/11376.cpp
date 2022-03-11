#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, cnt;
int mt[1001];
bool visited[1001];
vector<int> adj[1001];

bool dfs(int u)
{
    if(visited[u]) return false;
    visited[u] = true;

    for(int v : adj[u])
    {
        if(!mt[v])
        {
            mt[v] = u;
            return true;
        }
    }

    for(int v : adj[u])
    {
        if(dfs(mt[v]))
        {
            mt[v] = u;
            return true;
        }
    }

    return false;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    
    int t, v;
    for(int u = 1; u <= n; u++)
    {
        cin >> t;
        while(t--)
        {
            cin >> v;
            adj[u].push_back(v);
        }
    }

    for(int u = 1; u <= n; u++)
    {
        memset(visited, false, sizeof(bool) * (n + 1));
        if(dfs(u)) cnt++;
        memset(visited, false, sizeof(bool) * (n + 1));
        if(dfs(u)) cnt++;
    }
    
    cout << cnt;

    return 0;
}