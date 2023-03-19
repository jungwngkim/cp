#include <iostream>

using namespace std;

typedef long long i64;

i64 n, m;

i64 cnt(i64 x, int div) {
    i64 res = 0;
    for(x /= div; x > 0; x /= div) res += x;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    i64 n_2 = cnt(n, 2);
    i64 n_5 = cnt(n, 5);
    i64 m_2 = cnt(m, 2);
    i64 m_5 = cnt(m, 5);
    i64 nm_2 = cnt(n - m, 2);
    i64 nm_5 = cnt(n - m, 5);

    cout << min(n_2 - m_2 - nm_2, n_5 - m_5 - nm_5) << '\n';

    return 0;
}
