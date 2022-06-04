#include <iostream>

using namespace std;

pair<int, int> tree[400000];
int n, m, N;

pair<int, int> query(int l, int r)
{
    l += n; r += n;
    pair<int, int> ret = { 1000000001, 0 };
    while(l <= r)
    {
        if(l % 2 == 1) 
        {
            ret = { min(ret.first, tree[l].first), max(ret.second, tree[l].second) };
            l++;
        }
        if(r % 2 == 0)
        {
            ret = { min(ret.first, tree[r].first), max(ret.second, tree[r].second) };
            r--;
        }
        l /= 2; r /= 2;
    }
    return ret;
}

void update(int k, int x)
{
    k += n;
    tree[k] = { x, x };
    for(k /= 2; k >= 1; k /= 2)
    {
        tree[k] = { 
            min(tree[k * 2].first, tree[k * 2 + 1].first), 
            max(tree[k * 2].second, tree[k * 2 + 1].second) 
        };
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> m;

    int k = 0;
    for(int i = 0; i < 32; i++)
    {
        if(N >> i) k = i;
    }
    n = 1 << (k + 1);

    int x;
    for(int i = 0; i < N - 1; i++) { cin >> x; update(i, x); }
    cin >> x;
    for(int i = N - 1; i < n; i++) update(i, x);

    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        pair<int, int> q = query(a - 1, b - 1);
        cout << q.first << ' ' << q.second << '\n';
    }

    return 0;
}