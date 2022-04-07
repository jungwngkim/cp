#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int a[501], indegree[501];
bool adj[501][501];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
    {
        memset(adj, false, sizeof(adj));
        memset(indegree, 0, sizeof(indegree));
        
        int n, m;

        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                adj[a[i]][a[j]] = true;
                indegree[a[j]]++;
            }
        }

        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            if(adj[u][v]) swap(u, v);

            adj[u][v] = true;
            adj[v][u] = false;
            indegree[u]--;
            indegree[v]++;
        }

        queue<int> q;
        vector<int> res;

        for(int i = 1; i <= n; i++)
        {
            if(!indegree[i]) q.push(i);
        }

        bool unknown = false;
        while(!q.empty())
        {
            if(q.size() > 1)
            {
                unknown = true;
            }

            int u = q.front();
            q.pop();

            res.push_back(u);

            for(int v = 1; v <= n; v++)
            {
                if(adj[u][v])
                {
                    indegree[v]--;
                    if(!indegree[v]) q.push(v);
                }
            }
        }

        if(res.size() == n)
        {
            if(unknown)
            {
                cout << '?';
            }
            else
            {
                for(int x : res)
                {
                    cout << x << ' ';
                }
            }
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
        cout << '\n';
    }
    
    return 0;
}