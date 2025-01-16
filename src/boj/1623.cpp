#include <iostream>
#include <vector>

using namespace std;

int n, w[200001], dp1[200001], dp2[200001];
vector<int> c[200001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        c[p].push_back(i);
    }

    return 0;
}