#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int m = -1, mi, mj, x;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> x;
            if (m < x) {
                m = x, mi = i, mj = j;
            }
        }
    }

    cout << m << '\n' << mi << ' ' << mj;

    return 0;
}
