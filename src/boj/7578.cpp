#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[1000001];
ll t[2000000];

void update(int v, int tl, int tr, int pos, ll new_val)
{
    if(tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, new_val);
        else update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) 
{
    if(tr < l || r < tl) return 0;
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i = 0, x; i < n; i++)
    {
        cin >> x;
        a[x] = i;
    }

    ll ans = 0;
    for(int i = 0, x; i < n; i++)
    {
        cin >> x;
        ans += query(1, 0, n - 1, a[x] + 1, n - 1);
        update(1, 0, n - 1, a[x], 1);
    }
    cout << ans;

    return 0;
}