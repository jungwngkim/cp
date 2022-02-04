#include <iostream>
#include <algorithm>

#define N 300000
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

int n;
ll a[N], ans, two[N];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    two[0] = 1;
    for(int i = 1; i < n; i++) two[i] = (two[i - 1] * 2) % MOD;

    for(int i = 0; i < n; i++)
    {
        ans += a[i] * (two[i] - two[n - i - 1]);
        ans += MOD;
        ans %= MOD;
    }

    cout << ans % MOD;

    return 0;
}