#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 2502;
const int src = 2500, snk = 2501;
const int inf = 0x3f3f3f3f;

string tofu[50];
int price[6][6] = {
    {10, 8, 7, 5, -1, 1},
    {8, 6, 4, 3, -1, 1},
    {7, 4, 3, 2, -1, 1},
    {5, 3, 2, 2, -1, 1},
    {-1, -1, -1, -1, -1, -1},
    {1, 1, 1, 1, -1, 0},
};

int n, m;
int c[N][N], w[N][N], d[N], p[N];
bool inq[N];
vector<int> adj[N];

int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int conv(int y, int x) {
    return y * 50 + x;
}

void add_edge(int u, int v, int cap, int wht) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] = cap;
    w[u][v] = wht;
    w[v][u] = -wht;
}

bool spfa() {
    memset(d, 0x3f, sizeof(d));
    memset(inq, false, sizeof(inq));

    queue<int> q;
    q.push(src);
    inq[src] = true;
    d[src] = 0;

    bool ok = false;

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u == snk) ok = true;
        inq[u] = false;

        for (int v : adj[u]) {
            if (c[u][v] > 0 && d[v] > d[u] + w[u][v]) {
                d[v] = d[u] + w[u][v];
                p[v] = u;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }

    return ok;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> tofu[i];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if ((y + x) & 1) {
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    add_edge(conv(y, x), conv(ny, nx), 1, -price[tofu[y][x] - 'A'][tofu[ny][nx] - 'A']);
                }
                add_edge(src, conv(y, x), 1, 0);
            }
            add_edge(conv(y, x), snk, 1, 0);
        }
    }

    int min_cost = 0;
    while (spfa()) {
        int fl = inf;
        for (int x = snk; x != src; x = p[x]) fl = min(fl, c[p[x]][x]);
        min_cost += d[snk] * fl;
        for (int x = snk; x != src; x = p[x]) {
            c[p[x]][x] -= fl;
            c[x][p[x]] += fl;
        }
    }
    cout << -min_cost;

    return 0;
}