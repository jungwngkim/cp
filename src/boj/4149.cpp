#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull mul(ull a, ull b, ull m) {
    return (__uint128_t) a * b % m;
}

ull pow(ull a, ull b, ull m) {
    a %= m;
    ull res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a, m);
        }
        b >>= 1;
        a = mul(a, a, m);
    }
    return res;
}

bool miller_rabin(ull n, ull a) {
    ull k = 0, p = n - 1;
    while (!(p & 1)) {
        k++;
        p >>= 1;
    }
    ull x = pow(a, p, n);
    if (x == 1) return true;
    while (k--) {
        if (x == n - 1) return true;
        x = mul(x, x, n);
    }
    return false;
}

bool is_prime(ull n) {
    if (n <= 1) return false;
    for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a == n) return true;
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}

void pollard_rho(ull n, vector<ull> &v) {
    if(n == 1) return;
    if(is_prime(n)) {
        v.push_back(n);
        return;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    return 0;
}
