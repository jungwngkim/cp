#include <iostream>

using namespace std;

int n, a, b, c;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> a;
    for(int i = 1; i < n; i++)
    {
        cin >> b;
        c = gcd(a, b);
        cout << a / c << '/' << b / c << '\n';
    }
    
    return 0;
}