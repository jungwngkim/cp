#include <iostream>

using namespace std;

int t;
string s;

bool check() {
    int state = 1;
    for (char c : s) {
        switch (state) {
            case 1: state = c == '0' ? 9 : 2; break;
            case 2: state = c == '0' ? 3 : -1; break;
            case 3: state = c == '0' ? 4 : -1; break;
            case 4: state = c == '0' ? 4 : 5; break;
            case 5: state = c == '0' ? 9 : 6; break;
            case 6: state = c == '0' ? 7 : 6; break;
            case 7: state = c == '0' ? 4 : 8; break;
            case 8: state = c == '0' ? 9 : 2; break;
            case 9: state = c == '0' ? -1 : 8; break;
            default: return false;
        }
    }
    return state == 5 || state == 6 || state == 8;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> s;
        cout << (check() ? "YES" : "NO") << '\n';
    }

    return 0;
}