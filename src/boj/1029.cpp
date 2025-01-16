#include <iostream>
#include <cstring>

#define MAX 0x3f3f3f3f

using namespace std;

int n;
int dp[1 << 16][15][10], w[15][15];

int calc(int b, int u, int v) {
    int &m = dp[b][u][v];

    if (m != -1) return m;

    m = 1;

    for (int i = 1; i < n; i++) {
        if (w[u][i] < v) continue;
        if (b & (1 << i)) continue;
        m = max(m, calc(b | (1 << i), i, w[u][i]) + 1);
    }

    return m;
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        char c;
        cin >> c;
        w[i][j] = c - '0';
    }

    memset(dp, -1, sizeof(dp));

    cout << calc(1, 0, 0);

    return 0;
}