#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m, a[100][100];
    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> a[i][j];
    }

    for(int i = 0, t; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> t;
        a[i][j] += t;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}