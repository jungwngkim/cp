#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int n, m, l;
int a[100001];
pi b[100000];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) cin >> a[i];

    a[0] = -1000000001;
    a[n + 1] = 2000000001;

    sort(a + 1, a + n + 1);

    for(int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    sort(b, b + m);

    int ans = 0;
    for(int i = 1, j = 0; j < m; j++)
    {
        while(a[i] < b[j].first) i++;
        if(
            abs(a[i - 1] - b[j].first) + b[j].second <= l || 
            abs(a[i] - b[j].first) + b[j].second <= l
        ) ans++;
    }
    cout << ans;
    
    return 0;
}