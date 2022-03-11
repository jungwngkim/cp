#include <iostream>

#define N 100

using namespace std;

struct pt
{
    int x, y;

    bool operator<(const pt &p) const
    {
        if(x == p.x) return y < p.y;
        else return x < p.x;
    }
};

int t, na, nb;
pt pa[N], pb[N];

ll cross(pt p1, pt p2, pt p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

bool 1d_intersect(int x1, int x2, int x3)
{
    if(x1 > x2) swap(x1, x2);
    return x3 >= x1 && x3 <= x2;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--)
    {
        cin >> na >> nb;
        for(int i = 0; i < na; i++) cin >> pa[i].x >> pa[i].y;
        for(int i = 0; i < nb; i++) cin >> pb[i].x >> pb[i].y;

        if(na < nb)
        {
            swap(na, nb);
            swap(pa, pb);
        }

        if(na == 0 || na == 1 || nb == 0)
        {
            cout << "YES\n";
            continue;
        }
        else if(na == 2)
        {
            if(nb == 1)
            {
                if(cross(pa[0], pa[1], pb[0]))
                {
                    cout << "YES\n";
                    continue;
                }
                else
                {
                    if(1d_intersect(pa[0].x, pa[1].x, pb[0].x))
                    {
                        cout << "YES\n";
                        continue;
                    }
                    else
                    {
                        cout << "NO\n";
                        continue;
                    }
                }
            }
            else
            {

            }
        }
    }
    
    return 0;
}