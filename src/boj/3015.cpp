#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    stack<pair<int, long long>> s;
    int n, x;
    long long ans = 0;

    cin >> n;

    while (n--) {
        cin >> x;
        if (!s.size()) {
            s.push({ x, 1 });
        }
        else {
            while (s.size() && s.top().first < x) {
                ans += s.top().second;
                s.pop();
            }

            pair<int, long long> nx = { x, 1 };
            if (s.size() && s.top().first == x) {
                nx.second = s.top().second + 1; 
                ans += s.top().second;
                s.pop();
            }

            if (s.size()) {
                ans++;
            }

            s.push(nx);
        }
    }

    cout << ans;

    return 0;
}