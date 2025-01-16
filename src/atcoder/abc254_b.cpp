#include <iostream>

using namespace std;

int n, a[30][30];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        a[i][0] = 1;
        cout << 1 << ' ';
        for(int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}