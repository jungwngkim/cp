#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int x, n, a, b;
    cin >> x >> n;
    while(n--) {
        cin >> a >> b;
        x -= a * b;
    }

    cout << (x ? "No" : "Yes");
    
    return 0;
}