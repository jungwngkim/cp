#include <iostream>
#include <cstring>

using namespace std;

long long a[1000001];
int idx[11][10];

long long pow(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= 10;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    memset(a, -1, sizeof(a));
    for (int i = 0; i < 10; i++) idx[0][i] = a[i] = i;
    for (int len = 1, a_idx = 10; len <= 10; len++) {  // 각 자릿수의 첫번째 수
        for (int n = len; n < 10; n++) {
            idx[len][n] = a_idx;
            for (int k = idx[len - 1][len - 1]; k < idx[len - 1][n]; k++, a_idx++) {
                a[a_idx] = n * pow(len) + a[k];
            }
        }
    }

    int q;
    cin >> q;
    cout << a[q];

    return 0;
}
