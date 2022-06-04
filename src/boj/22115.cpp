#include <iostream>
#include <cstring>

using namespace std;

int n, k, a, dp[100001];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a;
		for(int j = 100000; j >= a; j--) {
			dp[j] = min(dp[j], dp[j - a] + 1);
		}
	}

	cout << (dp[k] == 0x3f3f3f3f ? -1 : dp[k]);

    return 0;
}