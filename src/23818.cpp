#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m, k;
int sign[100001];
int comp[100001];
bool is_bipartite[100001];
vector<pi> adj[100001];

void dfs1(int u, int c)
{
    comp[u] = c;

    for(pi edge : adj[u])
    {
        if(!comp[edge.first])
        {
            dfs1(edge.first, c);
        }
    }
}

void dfs2(int u, int s)
{
    sign[u] = s;

    for(pi edge : adj[u])
    {
        if(!sign[edge.first])
        {
            dfs2(edge.first, edge.second ? -s : s);
        }
    }

    for(pi edge : adj[u])
    {
        if(edge.second)
        {
            if(sign[edge.first] == sign[u])
            {
                is_bipartite[comp[u]] = false;
            }
        }
        else
        {
            if(sign[edge.first] != sign[u])
            {
                is_bipartite[comp[u]] = false;
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    while(m--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        adj[u].push_back({ v, t });
        adj[v].push_back({ u, t });
    }

    for(int u = 1; u <= n; u++)
        if(!comp[u]) 
            dfs1(u, u);

    for(int u = 1; u <= n; u++)
        if(u == comp[u])
        {
            is_bipartite[u] = true;
            dfs2(u, 1);
        }
    
    while(k--)
    {
        int u, v;
        cin >> u >> v;
        if(comp[u] == comp[v])
        {
            if(is_bipartite[comp[u]])
            {
                if(sign[u] == sign[v])
                {
                    cout << "Friend\n";
                }
                else
                {
                    cout << "Enemy\n";
                }
            }
            else
            {
                cout << "Error\n";
            }
        }
        else
        {
            cout << "Unknown\n";
        }
    }

    return 0;
}