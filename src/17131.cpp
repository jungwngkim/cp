#include <iostream>
#include <vector>

#define N 200000
#define MOD 1000000007

using namespace std;

typedef long long ll;

int n;
vector<int> pos[2 * N + 2];
int tree[2 * N + 2];

void update(int k)
{
    while(k <= 2 * N + 1)
    {
        tree[k]++;
        k += k & -k;
    }
}

ll query(int k)
{
    ll res = 0;
    while(k)
    {
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int _x, _y;
        cin >> _x >> _y;
        pos[_y + N + 1].emplace_back(_x + N + 1);
    }

    long long ans = 0;
    for(int y = 2 * N + 1; y > 0; y--)
    {
        for(int x : pos[y])
        {
            ans += query(x - 1) * (query(2 * N + 1) - query(x)) % MOD;
            ans %= MOD;
        }
        for(int x : pos[y])
        {
            update(x);
        }
    }
    cout << ans;
    
    return 0;
}