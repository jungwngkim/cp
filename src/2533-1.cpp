#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[1000001];
pair<int, int> dp[1000001][2];

void calc(int u, int p)
{
    dp[u][0] = { 0, 0 };
    dp[u][1] = { adj[u].size(), 1 };

    for(int v : adj[u])
    {
        if(v != p)
        {
            calc(v, u);
            
            if(dp[v][0].first >= dp[v][1].first)
            {
                dp[u][0].first += dp[v][0].first;
                dp[u][0].second += dp[v][0].second;
            }
            else
            {
                dp[u][0].first += dp[v][1].first;
                dp[u][0].second += dp[v][1].second;
            }

            dp[u][1].first += dp[v][0].first;
            dp[u][1].second += dp[v][0].second;
        }
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calc(1, -1);
    cout << min(dp[1][0].second, dp[1][1].second);
    // cout << (dp[1][0].first >= dp[1][1].first ? dp[1][0].second : dp[1][1].second);

    return 0;
}