#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define N 500

using namespace std;

struct Node { 
    int d, y, x; 

    bool operator<(const Node &o) const {
        return d < o.d;
    }
};

int n, m;
int cost[N][N], dist[N][N], srce[N][N], ans[N];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };

void dijk() {
    priority_queue<Node> q;

    memset(dist, 0x3f, sizeof(dist));
    memset(srce, -1, sizeof(srce));

    for(int y = 0; y < n; y++) {
        dist[y][m - 1] = cost[y][m - 1];
        srce[y][m - 1] = y;
    }

    for(int y = 0; y < n; y++) {
        q.push({ -dist[y][m - 1], y, m - 1 });
    }

    while(q.size()) {
        Node u = q.top();
        q.pop();

        if(dist[u.y][u.x] != -u.d) continue;

        for(int i = 0; i < 4; i++) {
            int vy = u.y + dy[i], vx = u.x + dx[i];

            if(vy < 0 || vy >= n || vx < 0 || vx >= m) continue;

            if(dist[vy][vx] > dist[u.y][u.x] + cost[vy][vx]) {
                dist[vy][vx] = dist[u.y][u.x] + cost[vy][vx];
                srce[vy][vx] = srce[u.y][u.x];
                q.push({ -dist[vy][vx], vy, vx });
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
        cin >> cost[y][x];
    }

    dijk();

    for(int y = 0; y < n; y++) {
        ans[srce[y][0]]++;
    }

    for(int y = 0; y < n; y++) {
        cout << ans[y] << '\n';
    }
}