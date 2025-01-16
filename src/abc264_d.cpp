#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s1 = "atcoder", s2;
    cin >> s2;

    map<char, int> m1, m2;
    for (int i = 0; i < 7; i++) {
        m1[s1[i]] = i;
        m2[s2[i]] = i;
    }

    int ans = 0;
    for(int i = 0; i < 7; i++) {
        for(int j = m2[s1[i]] - 1; j >= m1[s1[i]]; j--) {
            swap(s2[j], s2[j + 1]);
            m2[s2[j]] = j;
            m2[s2[j + 1]] = j + 1;
            ans++;
        }
    }
    cout << ans;

    return 0;
}