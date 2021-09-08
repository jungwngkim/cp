#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
    bool operator<(const struct Point &p) const
    {
        if (y == p.y)
            return x < p.x;
        return y < p.y;
    }
};

bool cmp(Point &a, Point &b)
{
    return a.x < b.x;
}

int dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<Point> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &v[i].x, &v[i].y);
    }
    sort(v.begin(), v.end(), cmp);

    set<Point> cand = {v[0], v[1]};
    int ans = dist(v[0], v[1]);
    int left = 0;
    for (int right = 2; right < n; right++)
    {
        Point rp = v[right];
        while (left < right)
        {
            Point lp = v[left];
            int dx = rp.x - lp.x;
            if (dx * dx > ans)
            {
                cand.erase(lp);
                left++;
            }
            else
            {
                break;
            }
        }

        int d = (int)sqrt((double)ans) + 1;
        Point lowerp = {-10001, rp.y - d};
        Point upperp = {10001, rp.y + d};

        auto lower = cand.lower_bound(lowerp);
        auto upper = cand.upper_bound(upperp);

        for (auto it = lower; it != upper; it++)
        {
            int currd = dist(rp, *it);
            if (currd < ans)
            {
                ans = currd;
            }
        }
        cand.insert(rp);
    }

    printf("%d", ans);

    return 0;
}