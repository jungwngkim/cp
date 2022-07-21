#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int n, m;
int sy, sx;
int a[30][30], b[30][30];
int dy[] = { 0, 0, 1, -1 }, dx[] = { 1, -1, 0, 0 };
bool visited[30][30];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
        cin >> a[y][x];
    }

    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
        cin >> b[y][x];

        if(a[y][x] != b[y][x]) {
            sy = y;
            sx = x;
        }
    }

    queue<pi> q;
    visited[sy][sx] = true;
    q.push({ sy, sx });

    while(q.size()) {
        auto [y, x] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(a[ny][nx] != a[sy][sx] || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ ny, nx });
        }
    }

    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
        if(visited[y][x]) {
            a[y][x] = b[sy][sx];
        }
    }

    bool ok = true;
    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
        if(a[y][x] != b[y][x]) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO");

    return 0;
}