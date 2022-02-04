#include <iostream>
#include <algorithm>
#include <vector>

#define N 100000

using namespace std;

typedef long long ll;

struct pt { ll x, y; };

int n;
pt a[N];

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
    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    pt p0 = *min_element(a, a + n, [](const pt &a, const pt &b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    sort(a, a + n, [&p0](const pt &a, const pt &b) {
        ll v = cross(p0, a, b);
        if(v) return v < 0;
        else return dist(p0, a) < dist(p0, b);
    });

    vector<pt> v;
    for(int i = 0; i < n; i++)
    {
        while(v.size() > 1 && !cw(v[v.size() - 2], v.back(), a[i])) v.pop_back();
        v.push_back(a[i]);
    }

    cout << v.size();
    
    return 0;
}