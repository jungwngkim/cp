#include <iostream>
#include <cmath>

#define EPS 1E-9
#define PI 3.14159265368979

using namespace std;

inline double circle_area(double r, double h)
{
    double t = acos(h / r);
    return r * r * t - h * sqrt(r * r - h * h);
}

inline double area(double r1, double r2, double d)
{
    if(d + r2 <= r1 + EPS) return PI * r2 * r2;
    if(r1 <= d - r2 + EPS) return 0;

    double h = (d * d + r1 * r1 - r2 * r2) / (2 * d);   
    return circle_area(r1, h) + circle_area(r2, d - h);
}

int main()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if(r1 < r2) swap(r1, r2);

    cout.precision(3);
    cout << fixed << area(r1, r2, d);
    
    return 0;
}