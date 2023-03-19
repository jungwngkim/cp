#include <iostream>

using namespace std;

string s;
int dp[5001], n;

int solve() {
    if(s[1] == '0') return 0;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2')
                dp[i] = dp[i - 2];
            else
                return 0;
        } else {
            dp[i] = dp[i - 1];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) 
                dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }
    return dp[n];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> s;
    n = s.size();
    s = "x" + s;
    cout << solve();

    return 0;
}
