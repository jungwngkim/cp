#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int l, r;
    cin >> l >> r;

    cout << string("atcoder").substr(l - 1, r - l + 1) << '\n';
    
    return 0;
}