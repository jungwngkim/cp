#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    cout << 2 * n << '\n';

    if (n % 4 != 0)
    {
        cout << n % 4;
        n -= n % 4;
    }
    
    for (int i = 0; i < n / 4; i++)
        cout << 4;
    cout << '\n';

    return 0;
}