#include <iostream>
#include <algorithm>

using namespace std;

int a[500000], b[500000];
int n, m;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        cout << (binary_search(a, a + n, b[i]) ? 1 : 0) << ' ';
    }

    return 0;
}