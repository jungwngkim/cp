#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, k, m;
int fact[2001], inv[2001];
vector<ll> n_factor, k_factor;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k >> m;

    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= 2000; i++) fact[i] = i * fact[i - 1] % m;

    inv[1] = 1;
    for (ll i = 2; i < m; i++) inv[i] = m - (m / i) * inv[m % i] % m;

    for (; n > 0; n /= m) n_factor.push_back(n % m);
    for (; k > 0; k /= m) k_factor.push_back(k % m);
    while (n_factor.size() > k_factor.size()) k_factor.push_back(0);

    ll ans = 1;

    for (int i = 0; i < n_factor.size(); i++) {
        ans *= (fact[n_factor[i]] * inv[fact[n_factor[i] - k_factor[i]]] % m * inv[fact[k_factor[i]]] % m);
        ans %= m;
    }

    cout << ans;

    return 0;
}