#include <iostream>

using namespace std;

typedef long long ll;

ll tree[2000000], n;

ll sum(ll l, ll r)
{
    l += n; r += n;
    ll s = 0;
    while(l <= r)
    {
        if(l % 2 == 1) s += tree[l++];
        if(r % 2 == 0) s += tree[r--];
        l /= 2; r /= 2;
    }
    return s;
}

void update(ll k, ll x)
{
    k += n;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2)
    {
        tree[k] = tree[k * 2] + tree[k * 2 + 1];
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        update(i, x);
    }

    m += k;
    for(int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1) update(b - 1, c);
        else cout << sum(b - 1, c - 1) << '\n';
    }

    return 0;
}