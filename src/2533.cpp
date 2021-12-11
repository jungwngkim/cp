#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[1000001];
int dp[1000001][2];

void calc(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = 1;

    for(int v : adj[u])
    {
        if(v != p)
        {
            calc(v, u);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
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
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}