#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, ans;
vector<pi> child[10001];

int dfs(int u) {
    int max1 = 0, max2 = 0;

    for(pi e : child[u]) {
        int max3 = e.second + dfs(e.first);
        if(max2 < max3) swap(max2, max3);
        if(max1 < max2) swap(max1, max2);
    }

    ans = max(ans, max1 + max2);

    return max1;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0, u, v, w; i < n - 1; i++) {
        cin >> u >> v >> w;
        child[u].push_back({ v, w });
    }

    dfs(1);

    cout << ans << '\n';

    return 0;
}