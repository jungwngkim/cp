#include <iostream>

#define MOD 1000000007LL

using namespace std;

typedef long long ll;

struct Matrix { ll a, b, c, d; };

Matrix mult(Matrix m1, Matrix m2)
{
    Matrix res;
    res.a = (m1.a * m2.a + m1.b * m2.c) % MOD;
    res.b = (m1.a * m2.b + m1.b * m2.d) % MOD;
    res.c = (m1.c * m2.a + m1.d * m2.c) % MOD;
    res.d = (m1.c * m2.b + m1.d * m2.d) % MOD;
    return res;
}

Matrix pow(Matrix m, ll n)
{
    Matrix res = { 1, 0, 0, 1 };
    while(n)
    {
        if(n & 1)
        {
            res = mult(res, m);
        }
        m = mult(m, m);
        n >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    if(n & 1)
    {
        cout << 0;
    }
    else
    {
        Matrix m = { 0, -1 + MOD, 1, 4 };
        m = pow(m, n / 2);
        cout << (m.a + 3 * m.c) % MOD;
    }
    
    return 0;
}