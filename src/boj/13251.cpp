#include <iostream>

using namespace std;

int n, a[50], s, k;

double c(int n, int k) {
    if (k > n) return 0;
    k = max(k, n - k);

    double res = 1;
    for (int i = n; i > k; i--)
        res *= i;
    for (int i = n - k; i > 0; i--)
        res /= i;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cout << fixed;
    cout.precision(20);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    cin >> k;

    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c(a[i], k);
    }
    cout << ans / c(s, k) << '\n';

    return 0;
}