#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, ans[100];
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        cin >> n >> m;

        for (int i = 0, p; i < n; i++) {
            cin >> p;
            q.push({p, i});
            pq.push(p);
        }

        for (int i = 0, j = 1; i < n; i++) {
            while (pq.top() != q.front().first) {
                q.push(q.front());
                q.pop();
            }
            ans[q.front().second] = j++;
            q.pop();
            pq.pop();
        }

        cout << ans[m] << '\n';
    }

    return 0;
}
