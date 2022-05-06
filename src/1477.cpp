#include <iostream>
#include <algorithm>

using namespace std;

int n, m, l;
int a[50], d[52];

bool ok(int dist) {
    int cnt = 0;
    for(int i = 0; i <= n; i++) {
        cnt += d[i] / dist;
        if(d[i] % dist == 0) cnt -= 1;
    }
    return cnt <= m;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m >> l;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    d[0] = a[0] - 0;
    d[n] = l - a[n - 1];
    for(int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    int lo = 1, hi = l, mid, ans = l;
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