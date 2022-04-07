#include <iostream>
#include <vector>
#include <cstring>

#define N 10000
#define M 50000
#define X 100000

using namespace std;

typedef pair<int, int> pi;

int t, n, m;
int tree[4 * X];
vector<int> pos[X + 1];
vector<pi> _inc[X + 1], _dec[X + 1];

void update(int v, int tl, int tr, int l, int r, int inc)
{
    if(l > r) return;

    if(tl == l && tr == r) tree[v] += inc;
    else
    {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(tm, r), inc);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, inc);
    }
}

int query(int v, int tl, int tr, int pos)
{
    if(tl == tr) return tree[v];
    else
    {
        int tm = (tl + tr) / 2;
        if(pos <= tm) return tree[v] + query(2 * v, tl, tm, pos);
        else return tree[v] + query(2 * v + 1, tm + 1, tr, pos);
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        for(int x = 0; x <= X; x++)
        {
            pos[x].clear();
            _inc[x].clear();
            _dec[x].clear();
        }
        
        cin >> n >> m;

        for(int i = 0; i < n; i++) 
        {
            int x, y;
            cin >> x >> y;
            pos[x].push_back(y);
        }

        for(int i = 0; i < 2 * m; i += 2) 
        {
            int x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1 >> y2;
            _inc[x1].push_back({ y1, y2 });
            _dec[x2].push_back({ y1, y2 });
        }

        int ans = 0;
        for(int x = 0; x <= X; x++)
        {
            for(pi seg : _inc[x])
            {
                update(1, 0, X, seg.first, seg.second, 1);
            }

            for(int y : pos[x])
            {
                ans += query(1, 0, X, y);
            }

            for(pi seg : _dec[x])
            {
                update(1, 0, X, seg.first, seg.second, -1);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}