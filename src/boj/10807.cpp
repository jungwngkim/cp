#include <iostream>

using namespace std;

int n, a[201], v;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        a[x + 100]++;
    }
    cin >> v;
    cout << a[v + 100];
    
    return 0;
}
