#include <iostream>
#include <vector>

using namespace std;

int dp[10001][2], weight[10001];
vector<int> adj[10001];

void calc(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = weight[u];

    for(int v : adj[u])
    {
        if(v != p)
        {
            calc(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> weight[i];
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calc(1, -1);
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}