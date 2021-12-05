#include <iostream>

#define Q 1000000007

using namespace std;

typedef long long ll;

ll tree[2000000], n, m, k;

ll mul(ll l, ll r)
{
    l += n; r += n;
    ll ret = 1;
    while(l <= r)
    {
        if(l % 2 == 1) ret = ret * tree[l++] % Q;
        if(r % 2 == 0) ret = ret * tree[r--] % Q;
        l /= 2; r /= 2;
    }
    return ret;
}

void update(ll k, ll x)
{
    k += n;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2)
    {
        tree[k] = tree[k * 2] * tree[k * 2 + 1] % Q;
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    
    for(int i = 0; i < 2 * n; i++) tree[i] = 1;

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        update(i, x);
    }

    m += k;
    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) update(b - 1, c);
        else cout << mul(b - 1, c - 1) << '\n';
    }

    return 0;
}