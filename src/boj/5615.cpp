#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull pow(ull a, ull n, ull mod) {
    ull res = 1LL;
    a %= mod;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

bool miller_rabin(ull a, ull n) {
    int k = 0;
    ull q = n - 1;
    while (!(q & 1)) {
        q >>= 1;
        k++;
    }
    ull t = pow(a, q, n);
    if (t == 1 || t == n - 1) return true;
    for (int i = 0; i < k - 1; i++) {
        t = t * t % n;
        if (t == n - 1) return true;
    }
    return false;
}

bool is_prime(ull n) {
    for (ull a : {2, 3, 5, 7, 11}) {
        if (a == n) return true;
        if (!miller_rabin(a, n)) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, ans = 0;
    ull a;
    cin >> n;
    while(n--) {
        cin >> a;
        if (is_prime(2 * a + 1)) ans++;
    }
    cout << ans;

    return 0;
}
