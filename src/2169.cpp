#include <iostream>

#define N 1001

using namespace std;

int a[N], l[N], r[N], dp[N][N], n, m;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int j = 1; j <= m; j++)
    {
        cin >> dp[1][j];
        dp[1][j] += dp[1][j - 1];
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[j];
        }

        r[1] = dp[i - 1][1] + a[1];
        l[m] = dp[i - 1][m] + a[m];

        for(int j = 2; j <= m; j++)
        {
            r[j] = max(r[j - 1], dp[i - 1][j]) + a[j];
        }

        for(int j = m - 1; j >= 1; j--)
        {
            l[j] = max(l[j + 1], dp[i - 1][j]) + a[j];
        }

        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(r[j], l[j]);
        }
    }
    cout << dp[n][m];
    
    return 0;
}