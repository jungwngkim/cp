#include <iostream>
#include <algorithm>

#define N 200000

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

    pt operator-(const pt &p) const
    {
        return { x - p.x, y - p.y };
    }
};

int n, m, t;
pt p[N], h[N];

ll dist(pt p1, pt p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

ll cross(pt p1, pt p2)
{
    return p1.x * p2.y - p2.x * p1.y;
}

ll cross(pt p1, pt p2, pt p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

        swap(p[0], *min_element(p, p + n));

        sort(p + 1, p + n, [](const pt &p1, const pt &p2) {
            ll c = cross(p[0], p1, p2);
            if(c) return c > 0;
            else return dist(p[0], p1) < dist(p[0], p2);
        });

        m = 0;
        for(int i = 0; i < n; i++)
        {
            while(m > 1 && cross(h[m - 2], h[m - 1], p[i]) <= 0) m--;
            h[m++] = p[i];
        }

        int l = 0, r = 0;
        for(int i = 1; i < m; i++)
        {
            if(h[i].x < h[l].x) l = i;
            if(h[i].x > h[r].x) r = i;
        }

        int ml = l, mr = r;
        for(int i = 0; i < m; i++)
        {
            if(cross(h[(l + 1) % m] - h[l], h[(r + 1) % m] - h[r]) > 0) r = (r + 1) % m;
            else l = (l + 1) % m;

            if(dist(h[l], h[r]) > dist(h[ml], h[mr])) ml = l, mr = r;
        }

        cout << h[ml].x << ' ' << h[ml].y << ' ' << h[mr].x << ' ' << h[mr].y << '\n';
    }
    
    return 0;
}