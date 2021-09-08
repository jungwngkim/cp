#include <iostream>
#define P 1000000007LL
#define SIZE 4000000

typedef long long ll;

using namespace std;

ll fac[SIZE + 1], facsq[SIZE + 1];

ll power(ll a, ll n)
{
    ll ans = 1LL, A = a;
    for (int i = 0; i < 31; i++)
    {
        if (((n >> i) & 1) == 1)
            ans = ans * A % P;

        A = A * A % P;
    }
    return ans;
}

int main()
{
    fac[1] = 1LL;
    for (ll i = 2; i <= SIZE; i++)
        fac[i] = (fac[i - 1] * i) % P;
    facsq[SIZE] = power(fac[SIZE], P - 2);
    for (ll i = SIZE - 1; i >= 0; i--)
        facsq[i] = (facsq[i + 1] * (i + 1)) % P;

    ll N, K;
    cin >> N >> K;
    cout << fac[N] * (facsq[K] * facsq[N - K] % P) % P;

    return 0;
}