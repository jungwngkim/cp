// 1753

#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pi;

vector<vector<pi>> adj;

void dijkstra(int n_v, int s)
{
    vector<int> d(n_v, INF);
    d[s] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int d_u = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (d[u] != d_u)
            continue;

        for (pi edge : adj[u])
        {
            int v = edge.first, len = edge.second;
            if (d_u + len < d[v])
            {
                d[v] = d_u + len;
                pq.push({d[v], v});
            }
        }
    }

    for (int d_i : d)
    {
        if (d_i == INF)
            cout << "INF" << '\n';
        else
            cout << d_i << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_v, n_e, s;
    cin >> n_v >> n_e >> s;
    adj = vector<vector<pi>>(n_v);

    int u, v, w;
    for (int i = 0; i < n_e; i++)
    {
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }

    dijkstra(n_v, s - 1);

    return 0;
}