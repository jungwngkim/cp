#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int n, k;
pi a[1002];
bool visited[1002];

int dist(int i, int j) {
    return (a[i].first - a[j].first) * (a[i].first - a[j].first) + 
        (a[i].second - a[j].second) * (a[i].second - a[j].second);
}

bool ok(int c) {
    queue<pi> q;
    q.push({ 0, 0 });

    memset(visited, false, sizeof(visited));
    visited[0] = true;

    while(!q.empty()) {
        int u = q.front().first, d = q.front().second;
        q.pop();

        if(u == n + 1) {
            return d <= k + 1;
        }

        for(int v = 1; v <= n + 1; v++) {
            if(!visited[v] && dist(u, v) <= c * c * 100) {
                visited[v] = true;
                q.push({ v, d + 1 });
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;

    a[0].first = a[0].second = 0;
    a[n + 1].first = a[n + 1].second = 10000;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int lo = 2, hi = 1415, mid, ans = 1415;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if(ok(mid)) {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans;
    
    return 0;
}