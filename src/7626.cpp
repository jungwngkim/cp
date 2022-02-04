#include <iostream>
#include <algorithm>

#define N 200000

using namespace std;

typedef long long ll;

struct Event 
{
    int x, y1, y2, inc;
};

int n, y_n;
int cnt[8 * N], len[8 * N], y[2 * N];
Event event[2 * N];

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

    if(cnt[v]) len[v] = y[tr + 1] - y[tl];
    else
    {
        if(tl != tr) len[v] = len[2 * v] + len[2 * v + 1];
        else len[v] = 0;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < 2 * n; i += 2)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        event[i] = { x1, y1, y2, 1 };
        event[i + 1] = { x2, y1, y2, -1 };
        y[i] = y1;
        y[i + 1] = y2;
    }

    sort(y, y + 2 * n);
    y_n = unique(y, y + 2 * n) - y;

    for(int i = 0; i < 2 * n; i += 2)
    {
        int idx1 = lower_bound(y, y + y_n, event[i].y1) - y;
        int idx2 = lower_bound(y + idx1, y + y_n, event[i].y2) - y;
        event[i].y1 = event[i + 1].y1 = idx1;
        event[i].y2 = event[i + 1].y2 = idx2 - 1;
    }

    sort(event, event + 2 * n, [](const Event &a, const Event &b) { return a.x < b.x; });

    update(1, 0, y_n - 1, event[0].y1, event[0].y2, 1);

    ll ans = 0;
    for(int i = 1; i < 2 * n; i++)
    {
        ans += ((ll) len[1]) * (event[i].x - event[i - 1].x);
        update(1, 0, y_n - 1, event[i].y1, event[i].y2, event[i].inc);
    }
    cout << ans;

    return 0;
}