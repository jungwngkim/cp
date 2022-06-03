#include <iostream>
#include <algorithm>

using namespace std;

int a[500000];
int n, m;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;
    for(int i = 0, x; i < m; i++) { 
        cin >> x;
        cout << (x == *lower_bound(a, a + n, x)) << ' ';
    }
    
    return 0;
}