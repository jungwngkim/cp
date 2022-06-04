#include <iostream>
#include <queue>

#define N 1500

using namespace std;

typedef pair<int, int> pi;

int r, c;
int sy = -1, sx, ty, tx;
bool used1[N][N], used2[N][N];
char b[N][N];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> r >> c;
    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            cin >> b[y][x];
            if(b[y][x] == 'L') {
                b[y][x] = '.';
                if(sy == -1) {
                    sy = y;
                    sx = x;
                }
                else {
                    ty = y;
                    tx = x;
                }
            }
        }
    }

    queue<pi> q1, q2, q3, q4;
    q1.push({sy, sx});
    used1[sy][sx] = true;

    for(int y = 0; y < r; y++) for(int x = 0; x < c; x++) {
        if(b[y][x] == '.') {
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if(!used2[ny][nx] && b[ny][nx] == 'X') {
                    used2[ny][nx] = true;
                    q3.push({ny, nx});
                }
            }
        }
    }

    int cnt = 0;
    for(;;cnt++) {
        // cout << cnt << '\n';

        bool success = false;

        while(q1.size()) {
            auto [y, x] = q1.front();
            q1.pop();

            // cout << y << ' ' << x << '\n';

            if(ty == y && tx == x) {
                success = true;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

                if(!used1[ny][nx]) {
                    used1[ny][nx] = true;
                    if(b[ny][nx] == '.') {
                        q1.push({ny, nx});
                    }
                    else {
                        q2.push({ny, nx});
                    }
                }
            }
        }

        if(success) {
            break;
        }

        while(q3.size()) {
            auto [y, x] = q3.front();
            q3.pop();

            // cout << y << ' ' << x << '\n';
            
            b[y][x] = '.';
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if(!used2[ny][nx] && b[ny][nx] == 'X') {
                    used2[ny][nx] = true;
                    q4.push({ny, nx});
                }
            }
        }
        
        q1 = q2;
        q3 = q4;

        while(q2.size()) q2.pop();
        while(q4.size()) q4.pop();
    }

    cout << cnt << '\n';
    
    return 0;
}