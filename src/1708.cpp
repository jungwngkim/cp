#include <iostream>
#include <algorithm>
#include <vector>

#define N 100000

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

int n;
pt p[N];

ll dist(pt a, pt b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll cross(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

bool cw(pt a, pt b, pt c)
{
    return cross(a, b, c) < 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    swap(p[0], *min_element(p, p + n));

    sort(p + 1, p + n, [](const pt &a, const pt &b) {
        ll v = cross(p[0], a, b);
        if(v) return v < 0;
        else return dist(p[0], a) < dist(p[0], b);
    });

    vector<pt> v;
    for(int i = 0; i < n; i++)
    {
        while(v.size() > 1 && !cw(v[v.size() - 2], v.back(), p[i])) v.pop_back();
        v.push_back(p[i]);
    }

    cout << v.size();
    
    return 0;
}