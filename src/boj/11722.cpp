#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int l[1001], a[1001], len;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = -a[i];
    }

    for (int i = 1; i <= n; i++) {
        auto pos = lower_bound(l + 1, l + len + 1, a[i]);
        *pos = a[i];

        if (pos == l + len + 1)
            len++;
    }

    cout << len << '\n';

    return 0;
}