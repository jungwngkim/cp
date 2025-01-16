#include <iostream>

using namespace std;

// # of scc
int n, a[50], g[50], g_cnt = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (g[i] == 0) {
            g_cnt++;

            g[i] = g_cnt;
            for (int j = a[i]; j != i; j = a[j]) {
                g[j] = g_cnt;
            }
        }
    }

    cout << (g_cnt == 1 ? 0 : g_cnt);

    return 0;
}
