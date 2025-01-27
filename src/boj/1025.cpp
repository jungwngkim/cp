#include <iostream>

using namespace std;

int n, m;
int a[9][9];

int calc(int i, int j) {
    int res = -1;
    for (int di = 0; di < n - 1; di++) 
        for (int dj = 0; dj < m - 1; di++)
            for (int l = 1; l <= min(n, m); l++) {
                int x = a[i + di]
            }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];
    
    int ans = -1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        ans = max(calc(i, j), ans);
    cout << ans;

    return 0;
}
