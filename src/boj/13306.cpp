#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[200001];

int p[200001], s[200001];

pair<int, int> q1[200001];
vector<int> q2[200001];

bool ans[200001];

int find(int x)
{
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if(a != b) 
    {
        if(s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;
    
    parent[1] = 1;
    for(int x = 2; x <= n; x++) cin >> parent[x];
    for(int x = 1; x <= n; x++) 
    {
        p[x] = x;
        s[x] = 1;
    }

    for(int i = 0, j = 0, q, u, v; i < (n - 1 + m); i++)
    {
        cin >> q;
        if(q)
        {
            cin >> u >> v;
            q1[++j] = { u, v };
        }
        else
        {
            cin >> u;
            q2[j].push_back(u);
        }
    }

    for(int j = m; j > 0; j--)
    {
        for(int x : q2[j]) merge(x, parent[x]);
        ans[j] = find(q1[j].first) == find(q1[j].second);
    }

    for(int j = 1; j <= m; j++) 
    {
        cout << (ans[j] ? "YES\n" : "NO\n");
    }

    return 0;
}