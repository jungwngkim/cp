#include <cstdio>

using namespace std;

int dp[501][501], cost[501], psum[501];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int K;
        scanf("%d", &K);

        for (int i = 1; i <= K; i++)
        {
            scanf("%d", &cost[i]);
            psum[i] = psum[i - 1] + cost[i];
        }

        for (int k = 1; k < K; k++)
        {
            for (int i = 1; i <= K - k; i++)
            {
                dp[i][i + k] = 50000000; // 500 * 10000 * log2(500) ≈ 500 * 10000 * 10
                for (int j = 0; j < k; j++)
                {
                    dp[i][i + k] = min(
                        dp[i][i + k], 
                        dp[i][i + j] + dp[i + j + 1][i + k] + psum[i + k] - psum[i - 1]);
                }
            }
        }

        printf("%d\n", dp[1][K]);
    }
    return 0;
}