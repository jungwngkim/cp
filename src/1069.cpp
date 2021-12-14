#include <iostream>
#include <cmath>

using namespace std;

inline double duration(double d, double j, double t)
{
    if(d < j) return min(2 * t, min(d, t + j - d));
    else if(d < 2 * j) return min(2 * t, min(d, t + d - j));
    else {
        int q = (int) d / j - 1;
        return q * t + duration(d - q * j, j, t);
    }
}

int main()
{
    double x, y, j, t;
    cin >> x >> y >> j >> t;

    double d = sqrt(x * x + y * y);
    
    cout.precision(9);
    if(j <= t) cout << fixed << d;
    else cout << fixed << duration(d, j, t);

    return 0;
}