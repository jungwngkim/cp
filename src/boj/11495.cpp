#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define N 2502
#define INF 0x3f3f3f3f
#define u(y, x) (((y) * 50) + (x))

using namespace std;

int q;
int n, m;
int s = 2500, t = 2501;
int b[50][50];
int c[N][N], f[N][N], lv[N], wk[N];
int dy[] = { 0, 1, -1, 0 }, dx[] = { 1, 0, 0, -1 };
vector<int> adj[N];

bool bfs() {
    memset(lv, -1, sizeof(lv));
    lv[s] = 0;

    queue<int> q;
    q.push(s);

    while(q.size()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(lv[v] == -1 && c[u][v] - f[u][v] > 0) {
                lv[v] = lv[u] + 1;
                q.push(v);
            }
        }
    }

    return lv[t] != -1;
}

int dfs(int u, int fl) {
    if(u == t) return fl;

    for(int &i = wk[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(lv[v] == lv[u] + 1 && c[u][v] - f[u][v] > 0) {
            if(int new_fl = dfs(v, min(fl, c[u][v] - f[u][v]))) {
                f[u][v] += new_fl;
                f[v][u] -= new_fl;
                return new_fl;
            }
        }
    }

    return 0;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    cin >> q;
    while(q--) {
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(b, 0, sizeof(b));

        int ans = 0, bsum = 0;
        
        cin >> n >> m;

        int nm = n * m;
        for(int i = 0; i < nm; i++) adj[i].clear();
        adj[s].clear();
        adj[t].clear();
        
        for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
            cin >> b[y][x];
            bsum += b[y][x];
        }

        for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
            if((x + y) & 1) {
                adj[t].push_back(u(y, x));
                adj[u(y, x)].push_back(t);
                c[u(y, x)][t] = b[y][x];
                // c[t][u(y, x)] = -b[y][x];
            }
            else {
                adj[s].push_back(u(y, x));
                adj[u(y, x)].push_back(s);
                c[s][u(y, x)] = b[y][x];
                // c[u(y, x)][s] = -b[y][x];
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    adj[u(y, x)].push_back(u(ny, nx));
                    adj[u(ny, nx)].push_back(u(y, x));
                    c[u(y, x)][u(ny, nx)] = INF;
                    // c[u(ny, nx)][u(y, x)] = -INF;
                }
            }
        }

        // for(int i = 0; i < n * m; i++) {
        //     if(adj[i].size()) {
        //         cout << i << " : "; 
        //         for(int x : adj[i]) {
        //             cout << x << ' ';
        //         }
        //         cout << '\n';
        //     }
        // }

        // for(int y = 0; y < n; y++) {
        //     for(int x = 0; x < m; x++) {
        //         cout << b[y][x] << ' ';
        //     }
        //     cout << '\n';
        // }

        while(bfs()) {
            memset(wk, 0, sizeof(wk));
            while(int new_fl = dfs(s, INF)) {
                ans += new_fl;
            }
        }

        ans += bsum - (ans * 2);

        cout << ans << '\n';
    }
    
    return 0;
}