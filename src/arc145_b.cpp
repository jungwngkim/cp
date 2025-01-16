#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n, a, b, k;
    cin >> n >> a >> b;

    if (a <= b)
    {
        cout << max(n - a + 1, 0LL);
    }
    else
    {
        if (n < a)
            cout << 0;
        else
        {
            k = n / a;
            cout << (k - 1) * b + min(n - k * a + 1, b);
        }
    }

    return 0;
}