#include <iostream>
#include <vector>

#define INF 0xffffffff

using namespace std;

struct Edge 
{
    int u, v, w;
};

vector<Edge> edge;

bool bellman_ford(int s, int n, vector<long long> & d)
{
    d = vector<long long>(n + 1, INF);
    d[s] = 0;

    for(int i=0; i<n-1; i++)
        for(Edge e : edge)
            if(d[e.u] < INF)
                d[e.v] = min(d[e.v], d[e.u] + e.w);

    for(Edge e : edge)
        if(d[e.u] < INF)
            if(d[e.u] + e.w < d[e.v])
                return false;

    return true;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    edge = vector<Edge>(m);
    for(int i = 0; i < m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    vector<long long> d;
    if(bellman_ford(1, n, d))
    {
        for(int i = 2; i <= n; i++)
        {
            cout << ((d[i] == INF) ? -1 : d[i]) << '\n';
        }
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}