#include <iostream>

using namespace std;

int memo[31][31] = {{
    0,
}};

int bridge(int l, int r)
{
    if (l == 1)
        return r;

    if (l == r)
        return 1;

    if (memo[l][r] == 0)
        memo[l][r] = bridge(l, r - 1) + bridge(l - 1, r - 1);

    return memo[l][r];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        cout << bridge(l, r) << '\n';
    }
    return 0;
}