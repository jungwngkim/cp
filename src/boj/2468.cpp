#include <cstring>
#include <iostream>

using namespace std;

int n, a[102][102], ans;
bool visited[102][102];
int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};

void dfs(int y, int x, int h) {
    visited[y][x] = true;

    for (int i = 0, ny, nx; i < 4; i++) {
        ny = y + dy[i], nx = x + dx[i];
        if (!visited[ny][nx] && a[ny][nx] >= h) {
            dfs(ny, nx, h);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> a[y][x];
        }
    }

    for (int h = 1, cnt; h <= 100; h++) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                if (!visited[y][x] && a[y][x] >= h) {
                    dfs(y, x, h);
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}