#include <iostream>

#define N 15
#define L 50
#define K 100

using namespace std;

typedef long long ll;

int n, k, r[N], len[N], ten[L + 1];
ll dp[1 << N][K];
string s[N];

ll gcd(ll a, ll b)
{
    if(!b) return a;
    if(a > b) swap(a, b);
    return gcd(a, b % a);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    cin >> k;

    for(int i = 0; i < n; i++)
    {
        len[i] = s[i].length();
        r[i] = 0;
        for(int j = 0; j < len[i]; j++)
        {
            r[i] = (r[i] * 10 + (s[i][j] - '0')) % k;
        }
    }

    ten[0] = 1;
    for(int i = 1; i <= L; i++)
    {
        ten[i] = (ten[i - 1] * 10) % k;
    }

    dp[0][0] = 1;
    for(int s = 0; s < (1 << n); s++) // for all sets
    {
        for(int j = 0; j < k; j++) // for all remainders
        {
            for(int i = 0; i < n; i++) // for all next numbers
            {
                if(!(s & (1 << i))) // if the set does not contain the number
                {
                    dp[s | (1 << i)][(j * ten[len[i]] + r[i]) % k] += dp[s][j];
                }
            }
        }
    }

    ll fac = 1;
    for(ll i = 2; i <= n; i++) fac *= i;

    ll z = gcd(fac, dp[(1 << n) - 1][0]);
    cout << dp[(1 << n) - 1][0] / z << '/' << fac / z;

    return 0;
}