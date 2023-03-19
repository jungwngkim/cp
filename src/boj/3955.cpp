#include <iostream>

using namespace std;

typedef long long ll;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1, y = 0;
    if (b) g = ext_gcd(b, a % b, y, x), y -= a / b * x;
    return g;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    ll k, c, x, y;

    cin >> t;
    while (t--) {
        cin >> k >> c;
        ll g = ext_gcd(k, c, x, y);
        if(g != 1) cout << "IMPOSSIBLE\n";
        else {
            while(x >= 0 || y <= 0) {
                x -= c;
                y += k;
            }
            if(y > 1000000000LL) cout << "IMPOSSIBLE\n";
            else cout << y << '\n';
        }
    }

    return 0;
}