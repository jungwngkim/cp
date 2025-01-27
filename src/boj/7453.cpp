#include <iostream>
#include <algorithm>

using namespace std;

int AB[16000000], CD[16000000];
int A[4000], B[4000], C[4000], D[4000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n;
    m = n * n;

    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[idx] = A[i] + B[j];
            CD[idx] = -(C[i] + D[j]);
            idx++;
        }
    }

    sort(AB, AB + m);
    sort(CD, CD + m);

    long long i = 0, j = 0, ii, jj, ans = 0;
    while (i < m && j < m) {
        if (AB[i] < CD[j]) {
            i++;
        }
        else if (AB[i] > CD[j]) {
            j++;
        }
        else {
            ii = i, jj = j;
            while (ii < m && AB[ii] == AB[i]) ii++;
            while (jj < m && CD[jj] == CD[j]) jj++;
            ans += (ii - i) * (jj - j);
            i = ii, j = jj;
        }
    }
    cout << ans << '\n';

    return 0;
}
