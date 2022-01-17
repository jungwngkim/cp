#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define N 500000

using namespace std;

int n, m, s, p;
int root[N + 1], cost[N + 1], dp[N + 1];
vector<int> order, scc;
vector<int> adj[N + 1], rev_adj[N + 1], scc_adj[N + 1];
bool visited[N + 1], exist[N + 1];

void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
    order.push_back(u);
}

void rev_dfs(int u)
{
    scc.push_back(u);
    visited[u] = true;
    for(int v : rev_adj[u])
    {
        if(!visited[v])
        {
            rev_dfs(v);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for(int u = 1; u <= n; u++)
    {
        cin >> cost[u];
    }

    cin >> s >> p;

    for(int i = 0; i < p; i++)
    {
        int u;
        cin >> u;
        exist[u] = true;
    }

    for(int u = 1; u <= n; u++)
    {
        if(!visited[u])
        {
            dfs(u);
        }
    }

    memset(visited, false, sizeof(bool) * (n + 1));
    for(auto u = order.rbegin(); u != order.rend(); u++)
    {
        if(!visited[*u])
        {
            scc.clear();

            rev_dfs(*u);

            for(int v : scc)
            {
                root[v] = *u;
                exist[*u] = exist[*u] || exist[v];
                if(v != *u)
                {
                    cost[*u] += cost[v];
                }
            }
        }
    }

    for(int u = 1; u <= n; u++)
    {
        for(int v : adj[u])
        {
            int root_u = root[u], root_v = root[v];
            if(root_u != root_v)
            {
                scc_adj[root_u].push_back(root_v);
            }
        }
    }

    queue<int> q;
    q.push(root[s]);

    dp[root[s]] = cost[root[s]];
    
    int ans = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(exist[u])
        {
            ans = max(ans, dp[u]);
        }

        for(int v : scc_adj[u])
        {
            if(dp[v] < dp[u] + cost[v])
            {
                dp[v] = dp[u] + cost[v];
                q.push(v);
            }
        }
    }
    cout << ans;

    return 0;
}