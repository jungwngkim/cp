#include <iostream>
#include <cstring>

using namespace std;

int n, a[50], dp[50][500001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    dp[0][a[0]] = a[0];

    for (int i = 1, p, h; i < n; i++) {
        for (int d = 0; d <= 500000; d++) {
            if (dp[i - 1][d] == -1) continue;

            p = dp[i - 1][d];
            h = a[i];

            // no use
            dp[i][d] = max(dp[i][d], p);

            // smaller tower
            if (d - h >= 0) dp[i][d - h] = max(dp[i][d - h], p);
            else dp[i][h - d] = max(dp[i][h - d], p + h - d);

            // taller tower
            if (d + h <= 500000) dp[i][d + h] = max(dp[i][d + h], p + h);
        }
    }

    cout << (dp[n - 1][0] ? dp[n - 1][0] : -1);

    return 0;
}