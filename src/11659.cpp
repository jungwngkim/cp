#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[100001], n, m;
    cin >> n >> m;
    a[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int j = 0; j < m; j++)
    {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
    return 0;
}