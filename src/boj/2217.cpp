#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a[100000];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i++) {
        a[i] *= (i + 1);
    }

    cout << *max_element(a, a + n);

    return 0;
}
