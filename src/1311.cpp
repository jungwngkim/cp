#include <iostream>
#include <cstring>

#define N 20
#define INF 0x3f3f3f3f

using namespace std;

int n, cost[N][N], dp[1 << N][N];

int calc(int b, int i)
{
    if(b == (1 << n) - 1) return 0;
    if(dp[b][i] != -1) return dp[b][i];

    dp[b][i] = INF;
    for(int j = 0; j < n; j++)
    {
        if(!(b & 1 << j))
        {
            dp[b][i] = min(dp[b][i], calc(b | (1 << j), i + 1) + cost[i][j]);
        }
    }

    return dp[b][i];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> cost[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout << calc(0, 0);

    return 0;
}