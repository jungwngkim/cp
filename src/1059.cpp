#include <iostream>
#include <algorithm>

#define N 50

using namespace std;

int n, m, a[N];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;

    sort(a, a + n);

    int idx = lower_bound(a, a + n, m) - a;

    if(a[idx] == m) cout << 0;
    else
    {
        cout << (a[idx] - m) * (m - a[idx - 1]) - 1;
    }
    
    return 0;
}