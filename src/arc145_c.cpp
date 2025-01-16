#include <iostream>

using namespace std;

long long m = 998244353;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    long long n, a;
    long long inv[5];
    cin >> n;

    a = 1;
    for(long long i = 2; i <= 2 * n; i++) {
        a = a * i % m;
    }

    inv[1] = 1;
    for(int i = 2; i < 5; ++i)
        inv[i] = m - (m/i) * inv[m%i] % m;

    cout << a * 2 % m * inv[3] % m;

    return 0;
}