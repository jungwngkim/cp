#include <iostream>

using namespace std;

int b[11][11];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int n = 0; n <= 10; n++) b[n][0] = 1;
    for (int n = 1; n <= 10; n++) {
        for (int k = 1; k <= n; k++) {
            b[n][k] = b[n - 1][k] + b[n - 1][k - 1];
        }
    }

    int n, k;
    cin >> n >> k;
    cout << b[n][k];

    return 0;
}
