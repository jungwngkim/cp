#include <iostream>

using namespace std;

int n;
long long a[50], s, ans;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (a[i] % s == 0)
            ans += a[i];
        else
            ans += s * (a[i] / s + 1);
    }

    cout << ans;

    return 0;
}