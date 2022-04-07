#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0) return b;
    if(a < b) swap(a, b);
    return gcd(a % b, b);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    int _gcd = gcd(a, b);
    cout << _gcd << '\n' << a * b / _gcd;
    
    return 0;
}