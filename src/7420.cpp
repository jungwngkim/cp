#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define N 1000
#define PI 3.14159265358979323

using namespace std;

typedef long long ll;

struct pt 
{
    ll x, y; 

    bool operator<(const pt &p) const
    {
        if(x == p.x) return y < p.y;
        else return x < p.x;
    }
};

int n, l;
pt p[N];

ll dist(pt p1, pt p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

ll cross(pt p1, pt p2, pt p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

ll ccw(pt p1, pt p2, pt p3)
{
    return cross(p1, p2, p3) > 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    swap(p[0], *min_element(p, p + n));

    sort(p + 1, p + n, [](const pt &p1, const pt &p2) {
        ll c = cross(p[0], p1, p2);
        if(c) return c > 0;
        else return dist(p[0], p1) < dist(p[0], p2);
    });

    vector<pt> v;
    for(int i = 0; i < n; i++)
    {
        while(v.size() > 1 && !ccw(v[v.size() - 2], v.back(), p[i])) v.pop_back();
        v.push_back(p[i]);
    }

    double s = 2 * l * PI;
    for(int i = 1; i < v.size(); i++) s += sqrt(dist(v[i - 1], v[i]));
    s += sqrt(dist(v.front(), v.back()));

    cout << round(s);
    
    return 0;
}