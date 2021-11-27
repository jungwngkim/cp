#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c;
    cin >> a >> b >> c;

    if(a < b)
    {
        if(a < c)
        {
            if(b < c) cout << b;
            else cout << c;
        }
        else cout << a;
    }
    else
    {
        if(b < c)
        {
            if(a < c) cout << a;
            else cout << c;
        }
        else cout << b;
    }
    
    return 0;
}