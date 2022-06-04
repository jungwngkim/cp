#include <iostream>
#include <cmath>

#define N 1000000
#define TREE_SIZE (1 << (int) (1 + ceil(log2((N)))))

using namespace std;

typedef long long ll;

ll tree[TREE_SIZE], n, m, k;

void update(int v, int tl, int tr, int pos, ll new_val)
{
    if(tl == tr)
    {
        tree[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2 * v, tl, tm, pos, new_val);
        else update(2 * v + 1, tm + 1, tr, pos, new_val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

ll sum(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(tl == l && tr == r) return tree[v];
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(tm, r)) +
           sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        update(1, 0, n - 1, i, x);
    }

    m += k;
    for(int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1) update(1, 0, n - 1, b - 1, c);
        else cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
    }

    return 0;
}