#include <iostream>

#define N 50

using namespace std;

int n, m;
int ans[N];
bool adj[N][N], used[N][N];

int cnt, p[N], r[N];

int find(int x)
{
    return p[x] = p[x] == x ? x : find(p[x]);
}

void merge(int a, int b)
{
    if(r[a] < r[b]) swap(a, b);
    p[b] = a;
    r[a]++;
    cnt--;
}

bool calc()
{
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
    {
        // cout << i << ' ' << find(i) << ' ' << j << ' ' << find(j) << '\n';
        if(adj[i][j] && find(i) != find(j)) 
        {
            merge(find(i), find(j));
            used[i][j] = true;
            ans[i]++, ans[j]++;
            m--;
        }
    }

    if(cnt > 1) return false; // not all components merged

    // visit remaining edges
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
    {
        if(adj[i][j] && !used[i][j] && m > 0)
        {
            ans[i]++, ans[j]++;
            m--;
        }
    }

    return m == 0;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    {
        char c;
        cin >> c;
        adj[i][j] = c == 'Y';
    }

    cnt = n;
    for(int x = 0; x < n; x++) p[x] = x;

    if(calc())
    {
        for(int x = 0; x < n; x++) cout << ans[x] << ' ';
    }
    else
    {
        cout << -1;
    }
    
    return 0;
}