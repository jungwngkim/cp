#include <iostream>

typedef long long ll;

using namespace std;

ll binpow(ll A, ll B, ll C)
{
    A %= C;
    ll res = 1;
    while (B > 0)
    {
        if (B & 1)
            res = res * A % C;
        A = A * A % C;
        B >>= 1;
    }
    return res;
}

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    cout << binpow(A, B, C);
    return 0;
}