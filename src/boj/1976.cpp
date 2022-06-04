#include <iostream>

using namespace std;

int p[201], size[201];

void create(int x)
{
    p[x] = x;
    size[x] = 1;
}

int find(int x)
{
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a != b) 
    {
        if(size[a] < size[b]) swap(a, b);
        p[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) create(i);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            int t; cin >> t; 
            if(t) merge(i, j);
        }

    int x1; cin >> x1;
    int root = find(x1);
    bool ans = true;
    for(int i = 2; i <= m; i++)
    {
        int x; cin >> x;
        if(root != find(x)) 
        {
            ans = false;
            break;
        }
    }

    if(ans) cout << "YES";
    else cout << "NO";

    return 0;
}