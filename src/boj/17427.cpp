#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    long long g = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        g += n / i * i;
    }
    cout << g;

    return 0;
}
