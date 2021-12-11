#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1E-9;

struct pt 
{
    double x, y;

    bool operator<(const pt &p) const
    {
        return (x < p.x - EPS) || (abs(x - p.x) < EPS && y < p.y - EPS);
    }

    bool operator==(const pt &p) const
    {
        return (abs(x - p.x) < EPS) && (abs(y - p.y) < EPS);
    }
};

struct line
{
    double a, b, c;

    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if(z > EPS) a /= z, b /= z, c /= z;
    }

    double dist(pt p)
    {
        return a * p.x + b * p.y + c;
    }
};

inline double intersect_1d(double a, double b, double c, double d)
{
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

inline double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

inline bool between(double l, double r, double x)
{
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

bool intersect(pt p1, pt p2, pt p3, pt p4, pt &left, pt &right)
{
    // 1. Check if segments can intersect
    if(!intersect_1d(p1.x, p2.x, p3.x, p4.x) || !intersect_1d(p1.y, p2.y, p3.y, p4.y)) return false;

    line l1(p1, p2), l2(p3, p4);
    double z = det(l1.a, l1.b, l2.a, l2.b);

    // 2. Check if segments are parallel or not
    if(abs(z) < EPS)
    {
        if(abs(l1.dist(p3)) > EPS || abs(l2.dist(p1)) > EPS) return false;

        if(p2 < p1) swap(p1, p2);
        if(p4 < p3) swap(p3, p4);
        left = max(p1, p3);
        right = min(p2, p4);
        return true;
    }
    else
    {
        left.x = right.x = -det(l1.c, l1.b, l2.c, l2.b) / z;
        left.y = right.y = -det(l1.a, l1.c, l2.a, l2.c) / z;
        return between(p1.x, p2.x, left.x) && between(p3.x, p4.x, right.x) && 
               between(p1.y, p2.y, left.y) && between(p3.y, p4.y, right.y);
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    pt p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    pt left, right;
    bool res = intersect(p1, p2, p3, p4, left, right);
    if(res)
    {
        cout << "Intersect ";
        if(left == right)
        {
            cout << "at Point: (" << left.x << ", " << left.y << ")\n";
        }
        else
        {
            cout << "at Segement: (" << left.x << ", " << left.y << ") to (" << 
                                       right.x << ", " << right.y << ")\n";
        }
    }
    else
    {
        cout << "Not Intersect\n";
    }
    return 0;
}