#include <iostream>
#include <map>

using namespace std;

map<char, char> m;
string s1 = "1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./ ", s2 = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. ";
string s;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < s1.length(); i++) {
        m[s1[i]] = s2[i];
    }

    while (getline(cin, s)) {
        for (char &c : s) {
            c = m[c];
        }
        cout << s << '\n';
    }

    return 0;
}