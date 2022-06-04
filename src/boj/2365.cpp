#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 102;
const int SRC = 100, SNK = 101;
const int INF = 0x3f3f3f3f;

int n;
int wsum;
int c[N][N], f[N][N], wk[N], lv[N];
vector<int> adj[N];

bool bfs() {
    memset(lv, 0, sizeof(lv));
    lv[SRC] = 1;

    queue<int> q;
    q.push(SRC);

    while(q.size()) {
        int here = q.front();
        q.pop();

        for(int there : adj[here]) {
            if(!lv[there] && c[here][there] - f[here][there] > 0) {
                lv[there] = lv[here] + 1;
                q.push(there);
            }
        }
    }

    // cout << lv[SNK] << ' ' << (bool)lv[SNK] << '\n';

    return lv[SNK];
}

int dfs(int here, int fl) {
    if(here == SNK) return fl;

    for(int &i = wk[here]; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if(lv[there] == lv[here] + 1 && c[here][there] - f[here][there] > 0) {
            if(int new_fl = dfs(there, min(fl, c[here][there] - f[here][there]))) {
                f[here][there] += new_fl;
                f[there][here] -= new_fl;
                return new_fl;
            }
        }
    }

    return 0;
}

bool ok(int k) {
    memset(f, 0, sizeof(f));

    for(int i = 0; i < n; i++) for(int j = 50; j < n + 50; j++) {
        c[i][j] = k;
    }

    int fl = 0;
    while(bfs()) {
        memset(wk, 0, sizeof(wk));
        while(int new_fl = dfs(SRC, INF)) {
            fl += new_fl;
        }
    }

    // cout << "fl: " << fl << '\n';

    return wsum == fl;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0, w; i < n; i++) {
        cin >> w;
        wsum += w;
        adj[i].push_back(SRC);
        adj[SRC].push_back(i);
        c[SRC][i] = w;
    }

    for(int i = 50, w; i < n + 50; i++) {
        cin >> w;
        adj[i].push_back(SNK);
        adj[SNK].push_back(i);
        c[i][SNK] = w;
    }

    for(int i = 0; i < n; i++) for(int j = 50; j < n + 50; j++) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    // for(int i = 0; i < N; i++) {
    //     if(adj[i].size()) {
    //         cout << i << " : ";
    //         for(int x : adj[i]) { 
    //             cout << x << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }

    int lo = 0, hi = 10000, mid, ans = 10000;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        // cout << mid << '\n';
        if(ok(mid)) {
            hi = mid - 1;
            ans = min(ans, mid);
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';

    ok(ans);

    for(int i = 0; i < n; i++) {
        for(int j = 50; j < n + 50; j++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}