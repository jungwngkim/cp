#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, a, x, d;

    cin >> n >> m >> a;
    d = m / 2 + 1;
    while (true) {
        cin >> x;
        x -= d;
        if (x == 0) break;
        a = (a + x + n) % n;
        if (a == 0) a = n;
        cout << a << '\n';
    }
    cout << 0 << '\n';

    return 0;
}