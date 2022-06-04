#include <iostream>
#include <algorithm>
#include <cstring>

#define N 75000

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int t, n, y_n;
int y[N + 1];
ll tree[N + 1];
pi pos[N + 1];

bool cmp(const pi & a, const pi & b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
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

void update(int k)
{
    while(k <= y_n)
    {
        tree[k]++;
        k += k & -k;
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> pos[i].first >> pos[i].second;
            y[i] = pos[i].second;
        }
        memset(tree, 0, sizeof(tree));

        sort(pos, pos + n, cmp);
        sort(y, y + n);
        y_n = unique(y, y + n) - y;

        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            int k = lower_bound(y, y + y_n, pos[i].second) - y + 1;
            sum += query(y_n) - query(k - 1);
            update(k);
        }
        cout << sum << '\n';
    }
    
    return 0;
}