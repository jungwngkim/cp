#include <iostream>

#define N 1000000

using namespace std;

int n, k;
int a[N], cnt[1000001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int _and = 0, _or = 0, _xor = 0;
    for (int i = 0; i <= 1000000; i++) {
        _xor += cnt[a[i] ^ k] * cnt[a[i]];
    }
    _xor /= 2;

    for(int i = 0; i < 20; i++) {
        if((k << i) & 1) {

        }
    }

    return 0;
}
