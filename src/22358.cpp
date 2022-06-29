#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int n, m, k, s, t;
vector<pi> adj1[100000], adj2[100000];
ll dp[100000][11];
const ll INF = 0x3f3f3f3f3f3f3f3f; 

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k >> s >> t;

    for(int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        if(u < v) adj1[u].push_back({v, w});
        else adj2[u].push_back({v, w});
    }


    
    return 0;
}