#include <iostream>

using namespace std;

int t, n, ans;
int h[44];  // h[i]: height가 i인 AVL tree의 최소 node 개수

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    h[1] = 1;
    for (int i = 2; i < 44; i++) h[i] = h[i - 1] + h[i - 2] + 1;

    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        while(h[ans] <= n) ans++;
        cout << ans - 1 << '\n';
    }
    return 0;
}
