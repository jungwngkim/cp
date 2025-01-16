#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f
#define SRC 200
#define SNK 201
#define LEN 202

using namespace std;

int n, m;
vector<int> adj[LEN];
int cap[LEN][LEN], cost[LEN][LEN];

void shortest_paths(vector<int> &d, vector<int> &p)
{
    d.assign(LEN, INF);
    d[SRC] = 0;
    vector<bool> inq(LEN, false);
    queue<int> q;
    q.push(SRC);
    p.assign(LEN, -1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u])
        {
            if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v])
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost()
{
    int cost = 0;
    vector<int> d, p;

    while (true)
    {
        shortest_paths(d, p);

        if (d[SNK] == INF)
            break;

        int f = INF;
        int cur = SNK;
        while (cur != SRC)
        {
            f = min(f, cap[p[cur]][cur]);
            cur = p[cur];
        }
        
        cost += f * d[SNK];
        cur = SNK;
        while (cur != SRC)
        {
            cap[p[cur]][cur] -= f;
            cap[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    return cost;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> cap[SRC][i];

        adj[SRC].push_back(i);
        adj[i].push_back(SRC);
    }

    for (int j = 100; j < 100 + m; j++)
    {
        cin >> cap[j][SNK];

        adj[j].push_back(SNK);
        adj[SNK].push_back(j);
    }

    for (int j = 100; j < 100 + m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cap[i][j] = INF;

            cin >> cost[i][j];
            cost[j][i] = -cost[i][j];

            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    cout << min_cost();

    return 0;
}
