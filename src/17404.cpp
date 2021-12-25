#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

int n, ans = INF;
int w[1000][3], dp[1000][3];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i][0] >> w[i][1] >> w[i][2];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i != j) dp[0][j] = INF;
            else dp[0][j] = w[0][j];
        }

        for(int j = 1; j < n; j++)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + w[j][0];
            dp[j][1] = min(dp[j - 1][2], dp[j - 1][0]) + w[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + w[j][2];
        }

        for(int j = 0; j < 3; j++)
        {
            if(i != j) ans = min(ans, dp[n - 1][j]);
        }
    }
    cout << ans;

    return 0;
}