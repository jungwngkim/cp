#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcd(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return g;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    ll a, b, x, y;

    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll g = gcd(a, b, x, y);

        while (y < 0) {
            y += a / g, x -= b / g;
        }

        if (x == 0 || y > 1000000000LL)
            cout << "IMPOSSIBLE\n";
        else {
            cout << y << '\n';
        }
    }
    
    return 0;
}