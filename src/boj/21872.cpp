#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int g;
    int k, l;
    cin >> g >> k >> l;
    while (g--) {
        int n, m;
        string s, t;
        cin >> n >> s >> m >> t;
        
        if (k == 1 || n <= m) cout << 'Y';
        if (k == 1 || m <= n) cout << 'S';
        cout << '\n';
    }

    return 0;
}
