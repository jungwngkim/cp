#include <iostream>

using namespace std;

typedef long long ll;

struct pt { ll x, y; };

int n;
pt p[100000];
ll area = 0, min_slice = (int) 1e18;

ll cross(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for(int i = 1; i <= n - 2; i++) {
        area += cross(p[0], p[i], p[i + 1]);
    }

    int p1 = 0, p2 = 2;
    while(p1 != n) {
        ll slice = 0;
        for(int i = p1 + 1; i <= p2 - 1; i++) {
            slice += cross(p[p1 % n], p[i % n], p[(i + 1) % n]);
        }

        min_slice = min(min_slice, abs(area - 4 * slice));

        if(area - 4 * slice < 0) {
            p1++;
            p2 = p1 + 2;
        }
        else {
            p2++;
        }
    }

    if(min_slice == (int) 1e18) {
        min_slice = area;
    }

    cout << min_slice;
    
    return 0;
}