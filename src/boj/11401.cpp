#include <iostream>

using namespace std;

const int N = 4000001;
const long long MOD = 1000000007;
long long n, k, fact[N], inv[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    fact[0] = fact[1] = 1;
    for (long long i = 2; i <= n; i++) fact[i] = i * fact[i - 1] % MOD;

    inv[1] = 1;
    for (long long i = 2; i < MOD; i++) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;

    cout << fact[n] * inv[fact[n - k]] % MOD * inv[fact[k]] % MOD;

    return 0;
}