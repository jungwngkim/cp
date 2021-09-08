#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0)
            break;

        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));
        int md = a + b + c - mx - mn;

        cout << ((mx * mx == mn * mn + md * md) ? "right" : "wrong");
        cout << '\n';
    }
    return 0;
}