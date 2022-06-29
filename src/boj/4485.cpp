#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Node { 
    int d, y, x; 

    bool operator<(const Node &o) const {
        return d < o.d;
    }

    bool operator>(const Node &o) const {
        return d > o.d;
    }
};

int n;
int c[125][125], d[125][125];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };

int dijk() {
    memset(d, 0x3f, sizeof(d));
    d[0][0] = c[0][0];

    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({ d[0][0], 0, 0 });

    while(q.size()) {
        Node u = q.top();
        q.pop();

        if(u.d != d[u.y][u.x]) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int vy = u.y + dy[i], vx = u.x + dx[i];

            if(vy < 0 || vy >= n || vx < 0 || vx >= n) continue;

            if(d[vy][vx] > d[u.y][u.x] + c[vy][vx]) {
                d[vy][vx] = d[u.y][u.x] + c[vy][vx];
                q.push({ d[vy][vx], vy, vx });
            }
        }
    }

    return d[n - 1][n - 1];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    for(int t = 1; ; t++) {
        cin >> n;
        if(n == 0) break;

        for(int y = 0; y < n; y++) for(int x = 0; x < n; x++) {
            cin >> c[y][x];
        }

        cout << "Problem " << t << ": " << dijk() << '\n';
    }
    
    return 0;
}