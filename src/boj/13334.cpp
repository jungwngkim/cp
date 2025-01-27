#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, d, ans = 0;
    priority_queue<pi> pq1, pq2;

    cin >> n;
    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        pq1.push({-r, l});
    }
    cin >> d;

    while (pq1.size()) {
        pi x = pq1.top();
        pq1.pop();

        int l = x.second, r = -x.first;
        pq2.push({-l, r});

        while (pq2.size() && -pq2.top().first < r - d) pq2.pop();

        ans = max(ans, (int) pq2.size());
    }
    cout << ans;

    return 0;
}
