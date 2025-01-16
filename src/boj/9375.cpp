#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        map<string, int> m;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            cin >> s;
            if (!m.count(s)) {
                m[s] = 0;
            }
            m[s]++;
        }

        int ans = 1;
        for (auto x : m) {
            ans *= (x.second + 1);
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}
