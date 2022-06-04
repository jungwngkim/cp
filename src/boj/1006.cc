#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, W, dp[10001], arr[2][10001];
        cin >> N >> W;

        for (int i = 1; i <= N; i++)
            cin >> arr[0][i];
        for (int i = 1; i <= N; i++)
            cin >> arr[1][i];

        arr[0][0] = arr[0][N];
        arr[1][0] = arr[1][N];


        // 1~8
        dp[0] = 0;
        // dp[1] = (arr[0][1] + arr[1][1]) <= W ? 1 : 2;
        for (int i = 1; i <= N; i++)
        {
            int inc1 = (arr[0][i] + arr[1][i]) <= W ? 1 : 2;
            int inc2 = ((arr[0][i] + arr[0][i - 1]) <= W ? 1 : 2) + ((arr[1][i] + arr[1][i - 1]) <= W ? 1 : 2);
            dp[i] = min(dp[i - 1] + inc1, dp[i - 2] + inc2);
        }

        cout << dp[N] << '\n';

        dp[0] = (arr[0][0] + arr[1][0]) <= W ? 1 : 2;
        for (int i = 1; i < N; i++)
        {
            int inc1 = (arr[0][i] + arr[1][i]) <= W ? 1 : 2;
            int inc2 = ((arr[0][i] + arr[0][i - 1]) <= W ? 1 : 2) + ((arr[1][i] + arr[1][i - 1]) <= W ? 1 : 2);
            dp[i] = min(dp[i - 1] + inc1, dp[i - 2] + inc2);
        }

        cout << dp[N-1] << '\n';

        cout << min(dp[N - 1], dp[N]) << '\n';
    }

    return 0;
}