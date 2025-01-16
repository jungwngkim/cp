#include <cstring>
#include <iostream>

using namespace std;

int c, r, k;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool m[1002][1002];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> c >> r >> k;

    if (c * r < k) {
        cout << 0;
    } else {
        for (int i = 1; i <= r; i++) m[0][i] = m[c + 1][i] = true;
        for (int i = 1; i <= c; i++) m[i][0] = m[i][r + 1] = true;
        int x = 1, y = 1;
        for (int i = 1, d = 0, nx, ny; i < k; i++) {
            m[x][y] = true;
            nx = x + dx[d], ny = y + dy[d];
            if (m[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + dx[d], ny = y + dy[d];
            }
            x = nx, y = ny;
        }
        cout << x << ' ' << y;
    }

    return 0;
}