#include <iostream>

using namespace std;

int p[500000], size[500000];

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
    if(size[a] < size[b]) swap(a, b);
    p[b] = a;
    size[a] += size[b];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) create(i);

    int turn;
    for(turn = 1; turn <= m; turn++)
    {
        int a, b; cin >> a >> b;
        a = find(a); b = find(b);
        if(a == b) break;
        merge(a, b);
    }
    cout << turn % (m + 1);

    return 0;
}