#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
vector<int> adj[300001];
ll dcnt, gcnt, cnt1[300001], cnt2[300001], cnt3[300001];

ll c(ll n) {
    if(n < 3) return 0;
    else return (n * (n - 1) * (n - 2)) / 6;
}

void calc(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            calc(v, u);

            cnt1[u]++;
            cnt2[u] += cnt1[v];
            cnt3[u] += cnt2[v];
        }
    }

    dcnt += cnt3[u] + cnt2[u] * (cnt1[u] - 1);
    gcnt += c(cnt1[u] + (p ? 1 : 0));
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    calc(1, 0);

    if(dcnt < gcnt * 3) cout << "G";
    else if(dcnt > gcnt * 3) cout << "D";
    else cout << "DUDUDUNGA";

    return 0;
}