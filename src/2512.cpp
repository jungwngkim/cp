#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[10000];

int main()
{
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;

    int l = 0, r = *max_element(a, a + n), mid, c, ans = 0;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        c = 0;
        for(int i = 0; i < n; i++) c += (a[i] < mid ? a[i] : mid);
        if(c <= m) 
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
    
    return 0;
}