#include <iostream>

using namespace std;

const int N = 4000001;
long long n, k, m, fact[N], inv[N], cnt[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k >> m;

    fact[0] = fact[1] = 1;
    for (long long i = 2; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        fact[i] = i * fact[i - 1];
        if (fact[i] % m == 0) {
            while (fact[i] % m == 0) {
                cnt[i]++;
                fact[i] /= m;
            }
        }
        fact[i] %= m;
    }

    inv[1] = 1;
    for (long long i = 2; i < m; i++) inv[i] = m - (m / i) * inv[m % i] % m;

    cout << cnt[n] << ' ' << cnt[n - k] << ' ' << cnt[k] << '\n';
    cout << fact[n] << ' ' << fact[n - k] << ' ' << fact[k] << '\n';
    // if (cnt[n] < cnt[n - k] + cnt[k])
    cout << (fact[n] * inv[fact[n - k]] * inv[fact[k]]) % m;
    // else
    //     cout << 0;

    return 0;
}