#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
int t[200001], cnt[200001];
vector<int> adj[200001];
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    memset(t, -1, sizeof(t));

    cin >> n;
    for(int u = 1, v; u <= n; u++) {
        cin >> v;
        while(v != 0) {
            adj[u].push_back(v);
            cin >> v;
        }
    }

    vector<int> r1, r2;
    cin >> m;
    for(int u; m; m--) {
        cin >> u;
        r1.push_back(u);
        t[u] = 0;
    }

    int time = 0;
    while(r1.size()) {
        time++;
        r2.clear();

        for(int u : r1) {
            for(int v : adj[u]) {
                cnt[v]++;
                if(t[v] == -1 && cnt[v] * 2 >= adj[v].size()) {
                    r2.push_back(v);
                    t[v] = time;
                }
            }
        }

        r1 = r2;
    }

    for(int u = 1; u <= n; u++) {
        cout << t[u] << ' ';
    }

    return 0;
}