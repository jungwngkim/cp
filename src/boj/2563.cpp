#include <iostream>

using namespace std;

bool a[100][100];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, ans = 0;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if(!a[i][j]) ans++;
                a[i][j] = true;
            }
        }
    }
    cout << ans;

    return 0;
}
