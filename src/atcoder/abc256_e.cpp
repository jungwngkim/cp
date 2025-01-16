#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, next_[200001], prev_[200001], cost[200001], state[200001];
long long ans;

void dfs(int u, int p) {
    prev_[p] = u;

    if(state[u] == 1) {
        int x = prev_[u];
        int min_cost = cost[u];
        while(x != u) {
            min_cost = min(cost[x], min_cost);
            x = prev_[x];
        }
        ans += min_cost;
        return;
    }

    if(state[u] == 2) return;

    state[u] = 1;
    dfs(next_[u], u);
    state[u] = 2;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> next_[i];
    for(int i = 1; i <= n; i++) cin >> cost[i];

    for(int i = 1; i <= n; i++) 
        if(!state[i]) dfs(i, 0);
    
    cout << ans;

    return 0;
}