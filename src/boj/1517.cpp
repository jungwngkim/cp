#include <iostream>
#include <algorithm>

#define MAXN 500000

using namespace std;

int n, N, tree[MAXN * 4];
pair<int, int> a[MAXN];

int query(int l, int r)
{
    l += N; r += N;
    int ret = 0;
    while(l <= r)
    {
        if(l % 2 == 1) ret += tree[l++];
        if(r % 2 == 0) ret += tree[r--];
        l /= 2; r /= 2;
    }
    return ret;
}

void update(int k)
{
    k += N;
    tree[k] = 1;
    for(k /= 2; k >= 1; k /= 2) tree[k] = tree[k * 2] + tree[k * 2 + 1];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;

    int k;
    for(int i = 0; i < 32; i++) if(n >> i) k = i;
    N = 1 << (k + 1);

    for(int i = 0; i < n; i++) 
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    for(int i = 0; i < n; i++) a[i].first = i + 1;

    sort(a, a + n, [](auto &l, auto &r) { return l.second < r.second; });

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += query(a[i].first + 1, n);
        update(a[i].first);
    }
    cout << ans;

    return 0;
}