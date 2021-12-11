#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int weight[10001], dp[10001][2];
vector<int> adj[10001], i_set[10001][2];

void calc(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = weight[u];
    i_set[u][1].push_back(u);

    for(int v : adj[u])
    {
        if(v != p)
        {
            calc(v, u);

            if(dp[v][0] > dp[v][1])
            {
                i_set[u][0].insert(i_set[u][0].end(), i_set[v][0].begin(), i_set[v][0].end());
                dp[u][0] += dp[v][0]; 
            }
            else
            {
                i_set[u][0].insert(i_set[u][0].end(), i_set[v][1].begin(), i_set[v][1].end());
                dp[u][0] += dp[v][1]; 
            }

            i_set[u][1].insert(i_set[u][1].end(), i_set[v][0].begin(), i_set[v][0].end());
            dp[u][1] += dp[v][0];

            // dp[u][0] += max(dp[v][0], dp[v][1]);
            // dp[u][1] += dp[v][0];
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

    if(dp[1][0] > dp[1][1])
    {
        cout << dp[1][0] << '\n';
        sort(i_set[1][0].begin(), i_set[1][0].end());
        for(auto it = i_set[1][0].begin(); it != i_set[1][0].end(); it++) cout << *it << ' ';
    }
    else
    {
        cout << dp[1][1] << '\n';
        sort(i_set[1][1].begin(), i_set[1][1].end());
        for(auto it = i_set[1][1].begin(); it != i_set[1][1].end(); it++) cout << *it << ' ';
    }

    return 0;
}