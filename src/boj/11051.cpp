#include <iostream>

using namespace std;

const int MOD = 10007;
int n, k, fact[1001], inv[MOD];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1000; i++) fact[i] = (i * fact[i - 1]) % MOD;

    inv[1] = 1;
    for (int i = 2; i < MOD; i++) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;

    cin >> n >> k;
    cout << fact[n] * inv[fact[n - k]] % MOD * inv[fact[k]] % MOD;

    return 0;
}