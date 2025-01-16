#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s;

    cin >> n >> s;

    int lo = 0, hi = n - 1;
    while (lo < hi && s[lo] == s[hi])
        lo++, hi--;

    // cout << lo << ' ' << hi << '\n';
    if (lo >= hi)
    {
        cout << "Yes";
    }
    else
    {
        if (s[lo] == 'B' && lo + 1 < hi)
            cout << "Yes";
        else
        {
            cout << (lo != 0 ? "Yes" : "No");
        }
    }

    return 0;
}