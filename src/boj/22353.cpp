#include <iostream>

using namespace std;

double a, d, k, p;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> a >> d >> k;

    p = d / 100.0;
    for(int i = 0; i < 1000; i++) {
        p *= 1 + k / 100.0;
    }
    cout << a * p;

    return 0;
}