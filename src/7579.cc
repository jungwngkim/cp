#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N, M, m[100], c[100];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &m[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &c[i]);

    int dp[10001];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        vector<pair<int, int>> v;
        for (int j = 0; j < 10001; j++)
        {
            if (dp[j] != -1)
                v.push_back({j + c[i], dp[j] + m[i]});
        }

        for (auto el : v)
        {
            dp[el.first] = max(dp[el.first], el.second);
        }
    }

    for (int i = 0; i < 10001; i++)
    {
        if (dp[i] >= M)
        {
            printf("%d", i);
            break;
        }
    }

    return 0;
}