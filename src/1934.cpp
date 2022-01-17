#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(!a) return b;
    if(a < b) swap(a, b);
    return gcd(a % b, b);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }
    
    return 0;
}