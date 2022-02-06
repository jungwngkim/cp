#include <iostream>
#include <algorithm>

#define N 2000

using namespace std;

typedef long long ll;

struct pt 
{ 
    ll x, y, idx; 

    bool operator<(const pt &p) const
    {
        if(x == p.x) return y < p.y;
        else return x < p.x;
    }
};

int t, n;
pt p[N];

ll dist(pt p1, pt p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
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
        for(int i = 0; i < n; i++) 
        {
            cin >> p[i].x >> p[i].y;
            p[i].idx = i;
        }

        swap(p[0], *min_element(p, p + n));

        sort(p + 1, p + n, [](const pt &p1, const pt &p2) {
            ll c = cross(p[0], p1, p2);
            if(c) return c > 0;
            else return dist(p[0], p1) < dist(p[0], p2);
        });

        int rev_idx = n - 1;
        while(!cross(p[0], p[rev_idx], p[rev_idx - 1])) rev_idx--;

        reverse(p + rev_idx, p + n);

        for(int i = 0; i < n; i++) cout << p[i].idx << ' ';
        cout << '\n';
    }
    
    return 0;
}