#include <iostream>

using namespace std;

int n, m, a[1000000];
long long ans;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}
