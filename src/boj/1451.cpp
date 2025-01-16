#include <iostream>

using namespace std;

int n, m;
long long a[51][51];
long long ans;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    char t;
    for(int y = 1; y <= n; y++) for(int x = 1; x <= m; x++) {
        cin >> t;
        a[y][x] = (t - '0') + a[y - 1][x] + a[y][x - 1] - a[y - 1][x - 1];
    }

    // for(int y = 1; y <= n; y++) {
    //     for(int x = 1; x <= m; x++) {
    //         cout << a[y][x] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int x1 = 1; x1 <= m - 2; x1++) 
    for(int x2 = x1 + 1; x2 <= m - 1; x2++) 
    for(int x3 = x2 + 1; x3 <= m; x3++) {
        ans = max(ans, a[n][x1] * (a[n][x2] - a[n][x1]) * (a[n][x3] - a[n][x2]));
    }

    for(int y1 = 1; y1 <= n - 2; y1++) 
    for(int y2 = y1 + 1; y2 <= n - 1; y2++) 
    for(int y3 = y2 + 1; y3 <= n; y3++) {
        ans = max(ans, a[y1][m] * (a[y2][m] - a[y1][m]) * (a[y3][m] - a[y2][m]));
    }

    for(int y = 1; y <= n - 1; y++) {
        for(int x = 1; x <= m - 1; x++) {
            long long tl, tr, bl, br;
            tl = a[y][x], tr = a[n][x] - a[y][x];
            bl = a[y][m] - a[y][x], br = a[n][m] - a[n][x] - a[y][m] + a[y][x];
            ans = max(ans, tl * tr * (bl + br));
            ans = max(ans, tl * bl * (tr + br));
            ans = max(ans, (tl + tr) * bl * br);
            ans = max(ans, (tl + bl) * tr * br);
        }
    }
    
    cout << ans;

    return 0;
}