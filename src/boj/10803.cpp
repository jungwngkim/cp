#include <iostream>
#include <cstring>

using namespace std;

int dp[10001][101];
const int inf = 0x3f3f3f3f;

int calc(int n, int m) {
    if(n < m) swap(n, m);

    if(dp[n][m] != inf) return dp[n][m];
    int &val = dp[n][m];

    if(n == 1) val = m;
    else if(m == 1) val = n;
    else if(n == m) val = 1;
    else if(n % m == 0) val = n / m;
    else {
        if(n > m * 3) val = min(val, calc(n - m, m) + 1);
        else {
            for(int i = 1; i <= n / 2; i++) val = min(val, calc(i, m) + calc(n - i, m));
            for(int i = 1; i <= m / 2; i++) val = min(val, calc(n, i) + calc(n, m - i));
        }
    }

    return val;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    memset(dp, 0x3f, sizeof(dp));

    int n, m;
    cin >> n >> m;
    cout << calc(n, m);
    
    return 0;
}