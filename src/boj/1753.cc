#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pii;

int n, n_e, k;
vector<vector<pii>> adj;
vector<int> d;

void dijkstra()
{
    d = vector<int>(n, INF);
    d[k] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, k});

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
    scanf("%d%d%d", &n, &n_e, &k);
    k--;

    adj = vector<vector<pii>>(n);
    int from, to, w;
    while (n_e--)
    {
        scanf("%d%d%d", &from, &to, &w);
        adj[from - 1].push_back({to - 1, w});
    }
}

void output()
{
    for (int len : d)
    {
        if (len != INF)
            printf("%d\n", len);
        else
            printf("INF\n");
    }
}

int main()
{
    input();
    dijkstra();
    output();
    return 0;
}