#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[10000];

bool ck(int x) {
    int idx = 0, cnt = 0;

    while(idx < n) {
        idx = upper_bound(a, a + n, a[idx] + x) - a;
        cnt++;
    }

    return cnt <= k;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int lo = 1, hi = 10000, mid, len = 10000;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if(ck(mid)) {
            hi = mid - 1;
            len = min(len, mid);
        }
        else {
            lo = mid + 1;
        }
    }

    int idx = 0, tmp, ans = 0;
    while(idx < n) {
        tmp = upper_bound(a, a + n, a[idx] + len) - a;
        ans += a[tmp - 1] - a[idx];
        idx = tmp;
    }
    cout << ans;
    
    return 0;
}