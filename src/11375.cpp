#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define N 1000
#define INF 2002

using namespace std;

typedef pair<int, int> pi;

int n, m;
int c[2 * N + 2][2 * N + 2];
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> & p)
{
    fill(p.begin(), p.end(), -1);
    p[s] = -2;
    queue<pi> q;
    q.push({ s, INF });

    while(!q.empty())
    {
        int u = q.front().first, flow = q.front().second;
        q.pop();

        for(int v : adj[u])
        {
            if(p[v] == -1 && c[u][v])
            {
                p[v] = u;
                int new_flow = min(flow, c[u][v]);
                if(v == t) return new_flow;
                q.push({ v, new_flow });
            }
        }
    }

    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0, new_flow;
    vector<int> p(n + m + 2);

    while((new_flow = bfs(s, t, p)))
    {
        flow += new_flow;

        int x = t;
        while(x != s)
        {
            c[p[x]][x] -= new_flow;
            c[x][p[x]] += new_flow;
            x = p[x];
        }
    }

    return flow;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    
    adj.resize(n + m + 2);
    for(int u = 1; u <= n; u++)
    {
        int vn; cin >> vn;
        adj[u].resize(vn);

        for(int i = 0; i < vn; i++)
        {
            cin >> adj[u][i];
            adj[u][i] += n;
        }

        for(int v : adj[u]) 
        {
            c[u][v] = 1;

            adj[v].push_back(u);
        }
    }

    for(int u = 1; u <= n; u++)
    {
        adj[0].push_back(u);
        c[0][u] = 1;

        adj[u].push_back(0);
    }

    for(int u = n + 1; u <= n + m; u++)
    {
        adj[u].push_back(n + m + 1);
        c[u][n + m + 1] = 1;

        adj[n + m + 1].push_back(u);
    }

    cout << max_flow(0, n + m + 1);
    
    return 0;
}