#include <iostream>

using namespace std;

int parent[1000001], set_size[1000001];

void make_set(int v)
{
    parent[v] = v;
    set_size[v] = 1;
}

int find_set(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(set_size[a] < set_size[b]) swap(a, b);
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++)
        make_set(i);
    
    int op, a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> op >> a >> b;
        if(op)
            cout << (find_set(a) == find_set(b) ? "YES" : "NO") << '\n';
        else
            union_sets(a, b);
    }

    return 0;
}