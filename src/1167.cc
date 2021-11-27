#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, d, visited[100001];
vector<pi> adj[100001];

int bfs(int u)
{
    int c_n = adj[u].size();

    if(c_n == 0) return 0;
    else if(c_n == 1) return bfs(adj[u][0].first) + adj[u][0].second;
    else 
    {
        int max_1 = 0, max_2 = 0;
        for(pi edge : adj[u])
        {
            int v = edge.first, w = edge.second;
            max_2 = max(max_2, bfs(v) + w);
            if(max_1 < max_2) swap(max_1, max_2);
        }

        if(d < max_1 + max_2) d = max_1 + max_2;

        return max_1;
    }
}

void build_tree(int u)
{
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i].first;
        if(!visited[v]) 
        {
            visited[v] = true;
            build_tree(v);
        }
        else
        {
            adj[u].erase(adj[u].begin() + i);
            i--;
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int u; cin >> u;
        while(true)
        {
            int v; cin >> v;
            if(v == -1) break;
            int w; cin >> w;
            adj[u].push_back({v, w});
        }
    }

    visited[1] = true;
    build_tree(1);

    d = max(d, bfs(1));
    cout << d;

    return 0;
}