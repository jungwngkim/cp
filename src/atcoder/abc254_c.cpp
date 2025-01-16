#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int n, k;
pi a[200000];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    bool ans = true;
    int lo = 0, hi;
    while(lo < n && ans) {
        pi x = { a[lo].first, 200001 };
        int hi = upper_bound(a + lo, a + n, x) - a;

        // cout << a[lo].first << ' ' << lo << ' ' << hi << '\n';

        set<int> s1, s2;
        for(int i = lo; i < hi; i++) {
            // cout << (a[i].second + k) % k << '\n';
            s1.insert((a[i].second + k) % k);
            s2.insert((i + k) % k);
        }

        if(s1 != s2) {
            ans = false;
            break;
        } 

        lo = hi;
    }

    cout << (ans ? "Yes" : "No");
    
    return 0;
}