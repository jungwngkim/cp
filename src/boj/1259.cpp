#include <iostream>

using namespace std;

bool is_palin(string s) {
    int n = s.length();
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    while(true) {
        cin >> s;
        if(s == "0") break;
        cout << (is_palin(s) ? "yes\n" : "no\n");
    }

    return 0;
}
