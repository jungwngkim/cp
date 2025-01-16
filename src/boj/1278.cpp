#include <iostream>

using namespace std;

void print(int n) {
    if (n == 1) cout << 1 << '\n';
    else {
        print(n - 1);
        cout << n << '\n';
        print(n - 1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    cout << ((1 << n) - 1) << '\n';
    print(n);
    cout << n;

    return 0;
}