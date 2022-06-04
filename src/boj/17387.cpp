#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1E-9;

struct pt 
{
    double x, y;
};

struct line
{
    double a, b, c;

    line(pt p1, pt p2)
    {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p1.y * p2.x;
        normalize();
    }

    void normalize()
    {
        double z = sqrt(a * a + b * b);
        if(z > EPS) a /= z, b /= z, c /= z;
    }

    double dist(pt p)
    {
        return a * p.x + b * p.y + c;
    }
};

inline double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

inline bool intersect_1d(double a, double b, double c, double d)
{
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

inline bool between(double a, double b, double c)
{
    if(a > b) swap(a, b);
    return a <= c + EPS && c <= b + EPS;
}

bool intersect(pt p1, pt p2, pt p3, pt p4)
{
    if(!intersect_1d(p1.x, p2.x, p3.x, p4.x) || !intersect_1d(p1.y, p2.y, p3.y, p4.y)) return false;

    line l1(p1, p2), l2(p3, p4);
    double z = det(l1.a, l1.b, l2.a, l2.b);
    if(abs(z) < EPS)
    {
        if(abs(l1.dist(p3)) > EPS || abs(l2.dist(p1)) > EPS) return false;
        return true;
    }
    else
    {
        double x = -det(l1.c, l1.b, l2.c, l2.b) / z, y = -det(l1.a, l1.c, l2.a, l2.c) / z;
        return between(p1.x, p2.x, x) && between(p1.y, p2.y, y) &&
               between(p3.x, p4.x, x) && between(p3.y, p4.y, y);
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    pt p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << intersect(p1, p2, p3, p4);
    return 0;
}