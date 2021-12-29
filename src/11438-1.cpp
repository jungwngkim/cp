#include <iostream>
#include <cmath>
#include <vector>

#define N 100000
#define K 18

using namespace std;

int n, m;
vector<int> adj[N + 1];

pair<int, int> euler[2 * N - 1][K];
int euler_idx[N + 1], idx;

int lg[2 * N], k;

void dfs(int u, int p, int depth)
{
    euler[idx][0] = { depth, u };
    euler_idx[u] = idx;
    idx++;

    for(int v : adj[u])
    {
        if(v != p)
        {
            dfs(v, u, depth + 1);
            euler[idx][0] = { depth, u };
            idx++;
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    lg[1] = 0;
    for(int i = 2; i < 2 * n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    k = ceil(log2(2 * n - 1));

    dfs(1, -1, 1);

    for(int j = 1; j < k; j++)
    {
        for(int i = 0; i + (1 << j) < 2 * n - 1; i++)
        {
            euler[i][j] = min(euler[i][j - 1], euler[i + (1 << (j - 1))][j - 1]);
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u = euler_idx[u], v = euler_idx[v];

        if(u > v) swap(u, v);

        int j = lg[v - u + 1];
        cout << min(euler[u][j], euler[v - (1 << j) + 1][j]).second << '\n';
    }
    
    return 0;
}