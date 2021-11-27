#include <iostream>
#include <cstring>

using namespace std;

int a[1000001], p[1000001];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;

    memset(a, -1, sizeof(a));
    memset(p, -1, sizeof(p));

    a[1] = 0; p[1] = -1;
    for(int i = 1; i <= n; i++) {
        if(i + 1 <= n && (a[i + 1] == -1 || a[i + 1] > a[i] + 1)) { a[i + 1] = a[i] + 1; p[i + 1] = i; }
        if(i * 2 <= n && (a[i * 2] == -1 || a[i * 2] > a[i] + 1)) { a[i * 2] = a[i] + 1; p[i * 2] = i; }
        if(i * 3 <= n && (a[i * 3] == -1 || a[i * 3] > a[i] + 1)) { a[i * 3] = a[i] + 1; p[i * 3] = i; }
    }

    cout << a[n] << '\n';
    while(n != -1) {
        cout << n << ' ';
        n = p[n];
    }

    return 0;
}