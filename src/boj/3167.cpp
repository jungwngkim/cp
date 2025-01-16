#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, m = 0;
    pair<int, int> a[1000];

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        m += a[i].first;
    }

    int min_checked = 0, max_checked = 0;

    // not_checked에서 우선적으로 빼면 min_checked
    int checked = 0, not_checked = 0;
    for (int i = 0; i < n; i++) {
        not_checked -= a[i].first;
        min_checked += a[i].first;
        if (not_checked < 0) {
            checked += not_checked;
            min_checked += not_checked;
            not_checked = 0;
        }
    
        not_checked += a[i].second;

        if (i % k == 0) {
            checked += not_checked;
            not_checked = 0;
        }
    }

    // checked에서 우선적으로 빼면 max_checked
    checked = 0, not_checked = 0;
    for (int i = 0; i < n; i++) {
        checked -= a[i].first;
        if (checked < 0) {
            not_checked += checked;
            max_checked -= checked;
            checked = 0;
        }

        not_checked += a[i].second;

        if (i % k == 0) {            
            checked += not_checked;
            not_checked = 0;
        }
    }

    cout << max_checked << ' ' << min_checked;
    return 0;
}