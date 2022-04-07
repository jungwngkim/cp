#include <iostream>

#define N 100001

using namespace std;

typedef long long ll;

ll a[N], tree[4 * N];

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        tree[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

long long query(int v, int tl, int tr, int l, int r) 
{
    if(l > tr || r < tl) return 0;
    if(l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

void update(int v, int tl, int tr, int pos, int new_val) 
{
    if(tl == tr)
    {
        tree[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, new_val);
        else update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    for(int x, y, a, b; q--;)
    {
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << query(1, 1, n, x, y) << '\n';
        update(1, 1, n, a, b);
    }
    
    return 0;
}