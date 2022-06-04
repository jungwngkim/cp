#include <iostream>
#include <cstring>

#define MAXN 100000

using namespace std;

int N, max_tree[MAXN * 4], min_tree[MAXN * 4];

bool query(int l, int r)
{
    int L = l + N, R = r + N;

    while(L <= R)
    {
        if(L % 2 == 1) 
        {
            if(max_tree[L] > r || min_tree[L] < l) return false;
            L++;
        }
        if(R % 2 == 0)
        {
            if(max_tree[R] > r || min_tree[R] < l) return false;
            R--;
        }
        L /= 2; R /= 2;
    }
    return true;
}

void update(int k, int x)
{
    int K = k + N;
    max_tree[K] = min_tree[K] = x;
    for(K /= 2; K >= 1; K /= 2)
    {
        min_tree[K] = min(min_tree[K * 2], min_tree[K * 2 + 1]);
        max_tree[K] = max(max_tree[K * 2], max_tree[K * 2 + 1]);
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;

        int pow;
        for(int i = 0; i < 32; i++) if(n >> i) pow = i;
        N = 1 << (pow + 1);

        memset(min_tree, 0x3f, sizeof(int) * N);
        memset(max_tree, -1, sizeof(int) * N);
        for(int i = 0; i < n; i++) update(i, i);

        while(k--)
        {
            int q, a, b; cin >> q >> a >> b;
            if(q)
            {
                cout << (query(a, b) ? "YES" : "NO") << '\n';
            }
            else
            {
                int t_a = min_tree[a + N], t_b = min_tree[b + N];
                update(a, t_b); update(b, t_a);
            }
        }
    }
    return 0;
}