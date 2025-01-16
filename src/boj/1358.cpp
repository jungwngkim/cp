#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int w, h, r, x, y, p, c = 0;
    cin >> w >> h >> x >> y >> p;
    r = h / 2;
    for (int i = 0, xi, yi, ci; i < p; i++) {
        cin >> xi >> yi;

        ci = 0;
        xi -= x, yi -= y;
        if (xi >= 0 && xi <= w && yi >= 0 && yi <= h) ci = 1;
        yi -= r;
        if (xi * xi + yi * yi <= r * r) ci = 1;
        xi -= w;
        if (xi * xi + yi * yi <= r * r) ci = 1;
        c += ci;
    }
    cout << c;

    return 0;
}