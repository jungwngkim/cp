#include <iostream>

using namespace std;

int f(long long n, long long k) {
    int a, b;
    for (int i = 0; i < 63; i++) {
        if ((n >> i) & 1) {
            a = i;
            break;
        }
    }

    b = 0;
    for (int i = 0; i < 63; i++) {
        if ((n >> i) & 1) {
            b++;
        }
    }

    return (a + b + k) % 2 == 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        long long k, l, r, ans = 0;
        cin >> k >> l >> r;
        if (!(l & 1)) {
            ans += f(l++, k);
        }
        if (r & 1) {
            ans += f(r--, k);
        }
        ans += (r - l + 1) / 2;
        cout << ans << '\n';
    }
}