#include <iostream>
#include <queue>
#include <functional>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pi;

int n, m, s, e;
vector<vector<pi>> adj;
vector<int> d, p;

void dijkstra(int s)
{
    d = vector<int>(n + 1, INF);
    p = vector<int>(n + 1, -1);
    d[s] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});

    while(!pq.empty())
    {
        int d_u = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(d[u] != d_u) continue;

        for(pi edge : adj[u])
        {
            int v = edge.first;
            int d_uv = edge.second;

            if(d_u + d_uv < d[v])
            {
                d[v] = d_u + d_uv;
                p[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    adj = vector<vector<pi>>(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cin >> s >> e;

    dijkstra(s);
    
    vector<int> path;
    int x = e;
    while(x != -1)
    {
        path.push_back(x);
        x = p[x];
    }

    cout << d[e] << '\n';
    cout << path.size() << '\n';
    for(auto it = path.rbegin(); it != path.rend(); it++)
        cout << *it << ' ';

    return 0;
}