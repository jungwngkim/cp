#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pi;

void dijkstra(int s, vector<int> & d, vector<vector<pi>> & adj)
{
    int n = adj.size();

    d = vector<int>(n, INF);
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
            int len = edge.second;

            if(d_u + len < d[v])
            {
                d[v] = d_u + len;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m, t, s, g, h, a, b, d;
        cin >> n >> m >> t >> s >> g >> h;

        vector<vector<pi>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }

        vector<int> d_s, d_g, d_h;
        dijkstra(s, d_s, adj);
        dijkstra(g, d_g, adj);
        dijkstra(h, d_h, adj);

        int x;
        vector<int> ans;
        for(int i = 0; i < t; i++)
        {
            cin >> x;
            if((d_s[x] == d_s[g] + d_g[h] + d_h[x]) || d_s[x] == d_s[h] + d_h[g] + d_g[x])
                ans.push_back(x);
        }

        sort(ans.begin(), ans.end());

        for(int x : ans)
            cout << x << ' ';
        cout << '\n';

    }
    return 0;
}