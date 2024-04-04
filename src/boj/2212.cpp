#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[10001], d[10001], dp[10001][1000];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + d[i];
        for (int c = 1; c < min(i, k); c++) {
            dp[i][c] = min(dp[i - 1][c] + d[i], dp[i - 1][c - 1]);
        }
    }

    cout << dp[n][k - 1];

    return 0;
}