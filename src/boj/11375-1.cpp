#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, count;
int mt[1001];
bool visited[1001];
vector<vector<int>> adj;

bool dfs(int &u)
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
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    adj.resize(n + 1);
    for(int u = 1; u <= n; u++)
    {
        int t;
        cin >> t;
        adj[u].resize(t);
        for(int &v : adj[u])
        {
            cin >> v;
        }
    }

    for(int u = 1; u <= n; u++)
    {
        memset(visited, false, sizeof(visited));
        if(dfs(u)) count++;
    }
    
    cout << count;
    
    return 0;
}