#include <iostream>
#include <cstring>

#define MOD 1000000000

using namespace std;

int dp[201][201];

int f(int n, int k)
{
    if(dp[n][k] != -1) return dp[n][k];

    if(n == 1) return dp[n][k] = k;
    if(k == 1) return dp[n][k] = 1;
    if(k == 2) return dp[n][k] = n + 1;

    return dp[n][k] = (f(n - 1, k) + f(n, k - 1)) % MOD;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    cout << f(n, k);
    
    return 0;
}