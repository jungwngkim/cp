#include <iostream>
#include <queue>

using namespace std;

int t;
priority_queue<int> q;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n) {
            while (n--) {
                int x;
                cin >> x;
                q.push(x);
            }
        } else {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }

    return 0;
}