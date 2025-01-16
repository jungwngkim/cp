#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define N 1000
#define LEN 2 * N + 3
#define SRC 0
#define SNK 2001
#define MID 2002
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pi;

int n, m, k;
int c[LEN][LEN];

vector<vector<int>> adj;

int bfs(vector<int> &p)
{
    fill(p.begin(), p.end(), -1);
    p[SRC] = -2;
    queue<pi> q;
    q.push({SRC, INF});

    while (!q.empty())
    {
        int u = q.front().first, flow = q.front().second;
        q.pop();

        for (int v : adj[u])
        {
            if (p[v] == -1 && c[u][v])
            {
                p[v] = u;
                int new_flow = min(flow, c[u][v]);
                if (v == SNK)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }

    return 0;
}

int max_flow()
{
    int flow = 0, new_flow;
    vector<int> p(LEN);

    while ((new_flow = bfs(p)))
    {
        flow += new_flow;

        int x = SNK;
        while (x != SRC)
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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    adj.resize(LEN);
    for (int u = 1, vn; u <= n; u++)
    {
        cin >> vn;
        adj[u].resize(vn);

        for (int i = 0; i < vn; i++)
        {
            cin >> adj[u][i];
            adj[u][i] += N;
        }

        for (int v : adj[u])
        {
            c[u][v] = 1;
            adj[v].push_back(u);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        c[SRC][u] = 1;
        adj[SRC].push_back(u);
        adj[u].push_back(SRC);

        c[MID][u] = 1;
        adj[MID].push_back(u);
        adj[u].push_back(MID);
    }

    c[SRC][MID] = k;
    adj[SRC].push_back(MID);
    adj[MID].push_back(SRC);

    for (int u = 1 + N; u <= 1 + N + m; u++)
    {
        c[u][SNK] = 1;
        adj[u].push_back(SNK);
        adj[SNK].push_back(u);
    }

    cout << max_flow();

    return 0;
}