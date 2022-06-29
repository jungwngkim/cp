#include <stdio.h>
#include <string.h>

#define max(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

int main()
{
    int N, dp[1001], ans = 0;
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int A;
        scanf("%d", &A);
        for (int j = 0; j < A; j++)
            if (dp[j] != -1)
                dp[A] = max(dp[A], dp[j] + A), ans = max(ans, dp[A]);
    }
    printf("%d", ans);
    return 0;
}