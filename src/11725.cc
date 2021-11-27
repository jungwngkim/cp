#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);

    int p[100001];
    memset(p, 0, sizeof(p));
    p[1] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(p[v] == 0)
            {
                p[v] = u;
                q.push(v);
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        cout << p[i] << '\n';
    }

    return 0;
}