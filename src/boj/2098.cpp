#include <iostream>
#include <cstring>

#define N 16
#define INF 0x3f3f3f3f

using namespace std;

int n, w[N][N], dp[1 << N][N];

int calc(int b, int u)
{
    if(b == (1 << n) - 1) 
    {
        return w[u][0] ? w[u][0] : INF;
    }
    if(dp[b][u] != -1) return dp[b][u];

    dp[b][u] = INF;
    for(int v = 1; v < n; v++)
    {
        if(!w[u][v]) continue;
        if(!(b & (1 << v)))
        {
            dp[b][u] = min(dp[b][u], calc(b | (1 << v), v) + w[u][v]);
        }
    }
    return dp[b][u];
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> w[i][j];
    memset(dp, -1, sizeof(dp));
    cout << calc(1, 0);

    return 0;
}