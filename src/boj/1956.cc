#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<vector<pi>> adj;

int dijkstra(int s)
{
    vector<int> d(n+1, INF);
    d[s] = 0;
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    
    while(!pq.empty()) {
        int d_u = pq.top().first;
        int u = pq.top().second;
        
        pq.pop();
        
        if(d_u != d[u]) continue;
        
        for(pi edge : adj[u]) {
            int v = edge.first;
            int d_v = d_u + edge.second;
            
            if(d_v < d[v]) {
                d[v] = d_v;
                pq.push({d_v, v});
            }
        }
    }

    // cout << s << ':';
    // for(int u = 1; u <= n; u++)
    //     cout << d[u] << ' ';
    // cout << '\n';

    int ans = INF;
    for(int u = 1; u <= n; u++) {
        if(u == s) continue;
        for(pi edge : adj[u]) {
            if(edge.first == s) {
                ans = min(ans, d[u] + edge.second);
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    int u, v, w;
    adj = vector<vector<pi>>(n+1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dijkstra(i));
    }
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}