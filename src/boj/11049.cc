#include <cstdio>

using namespace std;

int dp[501][501], cost[501][2], n;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &cost[i][0], &cost[i][1]);

    for (int k = 1; k < n; k++)
    {
        for (int left = 1; left <= n - k; left++)
        {
            int right = left + k;
            int add_cost = cost[left][0] * cost[right][1];
            dp[left][right] = 0x7fffffff;

            for (int mid = left; mid < right; mid++)
                dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right] + add_cost * cost[mid][1]);
        }
    }

    printf("%d", dp[1][n]);

    return 0;
}