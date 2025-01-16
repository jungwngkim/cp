#include <iostream>

using namespace std;

int cnt[200001][26];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++) {
        cnt[i][s[i - 1] - 'a'] = 1;
        for (int j = 0; j < 26; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }

    char c;
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> c >> l >> r;
        cout << cnt[r + 1][c - 'a'] - cnt[l][c - 'a'] << '\n';
    }

    return 0;
}
