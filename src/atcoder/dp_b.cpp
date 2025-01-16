#include <iostream>

using namespace std;

int n, k;
int h[100000];
int dp[100000];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];

    for(int i = 1; i < k; i++) {
        dp[i] = abs(h[i] - h[0]);
        for(int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    for(int i = k; i < n; i++) {
        dp[i] = dp[i-k] + abs(h[i] - h[i-k]);
        for(int j = i-k+1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n-1];

    return 0;
}