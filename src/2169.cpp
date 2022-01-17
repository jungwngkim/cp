#include <iostream>

#define N 1001

using namespace std;

int a[N], t, n, m;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    while(n--) for(int i = 1; i <= m; i++)
    {
        cin >> t;
        a[i] = max(a[i - 1], a[i]) + t;
        cout << a[i] << ' ';
        if(i == m) cout << '\n';
    }
    cout << a[m];
    
    return 0;
}