#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k, a[6], b[6];

    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < 6; i++) {
        if (a[i] == a[(i + 2) % 6] && a[(i + 1) % 6] == a[(i + 3) % 6]) {
            cout << (b[(i + 4) % 6] * b[(i + 5) % 6] - b[(i + 2) % 6] * b[(i + 1) % 6]) * k;
            break;
        }
    }

    return 0;
}