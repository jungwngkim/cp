#include <iostream>
#include <vector>

using namespace std;

int size[100001];
vector<int> adj[100001], tree[100001];

void build_tree(int u, int p)
{
    size[u] = 1;
    for(int v : adj[u])
    {
        if(v != p)
        {
            build_tree(v, u);
            size[u] += size[v];
        }
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n, r, q; cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build_tree(r, -1);

    for(int i = 0; i < q; i++)
    {
        int u; cin >> u; cout << size[u] << '\n';
    }

    return 0;
}