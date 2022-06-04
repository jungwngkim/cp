#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adj;
int N, E, v1, v2;

void dijkstra(int s, vector<int> &d)
{
    d = vector<int>(N, INF);
    d[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int d_v = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d_v != d[v])
            continue;

        for (pii edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }
}

void input()
{
    scanf("%d%d", &N, &E);

    adj = vector<vector<pii>>(N);
    int from, to, w;
    while (E--)
    {
        scanf("%d%d%d", &from, &to, &w);
        adj[from - 1].push_back({to - 1, w});
        adj[to - 1].push_back({from - 1, w});
    }

    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
}

void solve()
{
    vector<int> d_s, d_v, d_e;
    dijkstra(0, d_s);
    dijkstra(v1, d_v);
    dijkstra(N - 1, d_e);

    if (d_v[v2] == INF ||
        (d_s[v1] == INF && d_s[v2] == INF) ||
        (d_s[v1] == INF && d_e[v1] == INF) ||
        (d_s[v2] == INF && d_e[v2] == INF) ||
        (d_e[v1] == INF && d_e[v2] == INF))
    {
        printf("-1");
    }
    else
    {
        printf("%d", min(d_s[v1] + d_v[v2] + d_e[v2], d_s[v2] + d_v[v2] + d_e[v1]));
    }
}

int main()
{
    input();
    solve();
    return 0;
}