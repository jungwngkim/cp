#include <iostream>

using namespace std;

int f[41];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    f[1] = f[2] = 1;
    for(int i = 3; i <= 40; i++) f[i] = f[i - 1] + f[i - 2];

    int n;
    cin >> n;
    cout << f[n] << ' ' << n - 2;

    return 0;
}