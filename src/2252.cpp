#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[32001], res;
int n, m, state[32001];

void dfs(int u)
{
    state[u] = 1;
    for(int v : adj[u])
    {
        if(state[v] == 1) exit(0);
        if(!state[v])
        {
            dfs(v);
        }
    }
    state[u] = 2;
    res.push_back(u);
}

void topological_sort()
{
    for(int s = 1; s <= n; s++)
    {
        if(!state[s])
        {
            dfs(s);
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
    }

    topological_sort();
    for(auto it = res.rbegin(); it != res.rend(); it++)
    {
        cout << *it << ' ';
    }
    
    return 0;
}