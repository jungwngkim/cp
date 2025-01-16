#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, a[100];
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0, ans;
    for(ans = n - 1; ans >= 0; ans--) {
        cnt += a[ans];
        if(cnt >= 4) break;
    }

    cout << ans + 1;
    
    return 0;
}