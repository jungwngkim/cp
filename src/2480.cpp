#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> a >> b >> c;
    if(a == b)
    {
        if(a == c) cout << 10000 + a * 1000;
        else cout << 1000 + a * 100;
    }
    else
    {
        if(b == c) cout << 1000 + b * 100;
        else
        {
            if(a == c) cout << 1000 + a * 100;
            else cout << max(a, max(b, c)) * 100;
        }
    }
    
    return 0;
}