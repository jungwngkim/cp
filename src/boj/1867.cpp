#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int mt[501];
bool visited[501];
vector<int> adj[501];

bool dfs(int u)
{
    for(int v : adj[u]) 
    {
        if(!visited[v] && !mt[v])
        {
            visited[v] = true;
            mt[v] = u;
            return true;
        }
    }

    for(int v : adj[u]) 
    {
        if(!visited[v])
        {
            visited[v] = true;

            if(dfs(mt[v]))
            {
                mt[v] = u;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    int u, v;
    for(int i = 0; i < k; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int cnt = 0;
    for(int u = 1; u <= n; u++)
    {
        memset(visited, false, sizeof(visited));
        if(dfs(u)) cnt++;
    }

    cout << cnt;
    
    return 0;
}