#include <iostream>
#include <cstring>

using namespace std;

int n, m, a[50][50], l[10], ans;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    memset(a, -1, sizeof(a));
    cin >> n >> m;

    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++)
    {
        char c;
        cin >> c;
        a[y][x] = c - '0';
    }
    
    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++)
    {
        int t = a[y][x];
        for(int len = l[t]; len < min(n - y, m - x); len++)
        {
            if(t == a[y + len][x] && t == a[y][x + len] && t == a[y + len][x + len])
            {
                l[t] = len;
                ans = max(ans, l[t]);
            }
        }
    }

    cout << (ans + 1) * (ans + 1);

    return 0;
}