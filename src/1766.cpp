#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, m, in[32001];
vector<int> adj[32001];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;

    for(int x = 1; x <= n; x++)
    {
        if(!in[x])
        {
            pq.push(x);
        }
    }

    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();

        res.push_back(u);

        for(int v : adj[u])
        {
            in[v]--;
            if(!in[v])
            {
                pq.push(v);
            }
        }
    }

    for(int x : res) cout << x << ' ';
    
    return 0;
}