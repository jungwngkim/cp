#include <iostream>

using namespace std;

int n, k;
long long a[100001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    long long ans = 1LL << 63;
    for (int i = k; i <= n; i++) {
        ans = max(ans, a[i] - a[i - k]);
    }
    cout << ans;
}