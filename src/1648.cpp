#include <iostream>
#include <cstring>

#define N 14
#define MOD 9901

using namespace std;

int n, m;
int dp[N * N][1 << N];

int go(int i, int b)
{
    if(i == n * m)
    {
        return !b;
    }
    
    if(i > n * m)
    {
        return 0;
    }

    if(dp[i][b] != -1)
    {
        return dp[i][b];
    }

    if(b & 1)
    {
        return dp[i][b] = go(i + 1, b >> 1);
    }
    else
    {
        if(!(b & 2) && ((i + 1) % m))
        {
            return dp[i][b] = (go(i + 1, (b | (1 << m)) >> 1) + go(i + 2, b >> 2)) % MOD;
        }
        else
        {
            return dp[i][b] = go(i + 1, (b | (1 << m)) >> 1);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    cout << go(0, 0);
    
    return 0;
}