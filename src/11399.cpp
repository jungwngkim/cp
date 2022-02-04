#include <iostream>
#include <algorithm>

using namespace std;

int n, ans, a[1000];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    for(int i = 0; i < n; i++) ans += a[i];
    cout << ans;
    
    return 0;
}