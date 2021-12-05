#include <iostream>

#define MAXN 100000

using namespace std;

typedef long long ll;

ll tree[MAXN * 4], N;

ll query(int k)
{
    k += N;
    ll sum = tree[k];
    for(k /= 2; k >= 1; k /= 2) sum += tree[k];
    return sum;
}

void update(int l, int r, int k)
{
    l += N; r += N;
    while(l <= r)
    {
        if(l % 2 == 1) tree[l++] += k;
        if(r % 2 == 0) tree[r--] += k;
        l /= 2; r /= 2;
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    int e; 
    for(int i = 0; i < 32; i++) if(n >> i) e = i;
    N = 1 << (e + 1);

    for(int i = 0; i < n; i++) cin >> tree[i + N];

    int m; cin >> m;

    while(m--)
    {
        int q; cin >> q;
        if(q == 1)
        {
            int i, j, k; cin >> i >> j >> k;
            update(i - 1, j - 1, k);
        }
        else
        {
            int x; cin >> x;
            cout << query(x - 1) << '\n';
        }
    }
    return 0;
}