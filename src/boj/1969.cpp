#include <iostream>

using namespace std;

int n, m;
int cnt[1000][4];

int conv1(char c) {
    if (c == 'A')
        return 0;
    else if (c == 'C')
        return 1;
    else if (c == 'G')
        return 2;
    else
        return 3;
}

char conv2(int i) {
    if (i == 0)
        return 'A';
    else if (i == 1)
        return 'C';
    else if (i == 2)
        return 'G';
    else
        return 'T';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            cnt[j][conv1(c)]++;
        }
    }

    int w = 0;
    string s = "";
    for (int i = 0; i < m; i++) {
        int max_idx = 0;
        for (int j = 1; j < 4; j++) {
            if (cnt[i][j] > cnt[i][max_idx]) max_idx = j;
        }
        s += conv2(max_idx);
        w += n - cnt[i][max_idx];
    }

    cout << s << '\n' << w;

    return 0;
}