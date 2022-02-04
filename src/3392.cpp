#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_N 10000
#define MAX_Y 30000
#define TREE_SIZE (1 << (int) (1 + ceil(log2(MAX_Y))))

using namespace std;

struct Event
{
    int x, y1, y2, inc;
};

int n;
int cnt[TREE_SIZE], len[TREE_SIZE];
Event event[2 * MAX_N];

void update(int v, int tl, int tr, int l, int r, int inc)
{
    if(l > r) return;
    
    if(tl == l && tr == r) cnt[v] += inc;
    else
    {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(tm, r), inc);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, inc);
    }

    if(cnt[v]) len[v] = tr - tl + 1;
    else
    {
        if(tl == tr) len[v] = 0;
        else len[v] = len[2 * v] + len[2 * v + 1];
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < 2 * n; i += 2)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        event[i] = { x1, y1, y2 - 1, 1 };
        event[i + 1] = { x2, y1, y2 - 1, -1 };
    }
    
    sort(event, event + 2 * n, [](const Event &a, const Event &b) { return a.x < b.x; });

    update(1, 0, MAX_Y, event[0].y1, event[0].y2, 1);

    int ans = 0;
    for(int i = 1; i < 2 * n; i++)
    {
        ans += len[1] * (event[i].x - event[i - 1].x);
        update(1, 0, MAX_Y, event[i].y1, event[i].y2, event[i].inc);
    }
    cout << ans;

    return 0;
}