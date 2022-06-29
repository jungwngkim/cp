#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int k, q, r, b, n, p;
    cin >> k >> q >> r >> b >> n >> p;
    cout << 1 - k  << ' ' << 1 - q  << ' ' << 2 - r  << ' ' << 2 - b  << ' ' << 2 - n  << ' ' << 8 - p;

    return 0;
}