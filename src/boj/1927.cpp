#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    priority_queue<int, vector<int>, greater<int>> q;
    int n, x;

    cin >> n;
    while (n--) {
        cin >> x;
        if (!x) {
            if (q.empty()) {
                cout << 0 << '\n';
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        } else {
            q.push(x);
        }
    }

    return 0;
}