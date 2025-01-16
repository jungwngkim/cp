#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int i, l;
        string s;
        cin >> s;
        l = s.length();
        for (i = 0; i < l / 2; i++) {
            if (s[i] != s[l - i - 1]) break;
        }
        cout << (i == l / 2) << ' ' << (i + 1) << '\n';
    }

    return 0;
}
