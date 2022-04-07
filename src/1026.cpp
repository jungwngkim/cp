#include <iostream>
#include <algorithm>

using namespace std;

int n, a[50], b[50];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n, [](const int &b1, const int &b2) { return b1 > b2; });
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * b[i];
    cout << ans;

    return 0;
}