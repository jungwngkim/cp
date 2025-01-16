#include <iostream>

using namespace std;

int t, n, dp[2001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    dp[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 2000; j >= i; j--) {
            dp[i] += dp[j - i];
            dp[i] %= 100999;
        }
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}