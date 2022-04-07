#include <iostream>
#include <cstring>

#define MOD 1000000003

using namespace std;

int dp[1001][1001];

int f(int n, int k)
{
    if(dp[n][k] != -1) return dp[n][k];

    if(n / 2 < k) return dp[n][k] = 0;
    else if(n / 2 == k) return dp[n][k] = ((n % 2 == 0) ? 2 : n);
    else if(k == 1) return dp[n][k] = n;
    else return dp[n][k] = ((f(n - 1, k) + f(n - 2, k - 1)) % MOD);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    cout << f(n, k);

    return 0;
}