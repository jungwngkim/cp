#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node { int t1, t2, t3; };

int n, ans;
Node a[51];

int mt[51];
bool visited[51];
vector<int> adj[51];

bool dfs(int u)
{
    for(int v : adj[u])
    {
        if(!visited[v] && !mt[v])
        {
            visited[v] = true;
            mt[v] = u;
            return true;
        }
    }

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            
            if(dfs(mt[v]))
            {
                mt[v] = u;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i].t1 >> a[i].t2 >> a[i].t3;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            
            if(a[i].t1 == a[j].t1 && a[i].t2 == a[j].t2 && a[i].t3 == a[j].t3)
            {
                if(i < j)
                {
                    adj[i].push_back(j);
                }
            }
            else if(a[i].t1 >= a[j].t1 && a[i].t2 >= a[j].t2 && a[i].t3 >= a[j].t3)
            {
                adj[i].push_back(j);
            }
        }
    }

    for(int u = 1; u <= n; u++)
    {
        memset(visited, false, sizeof(visited));
        dfs(u);
        memset(visited, false, sizeof(visited));
        dfs(u);
    }

    for(int v = 1; v <= n; v++) if(!mt[v]) ans++;

    cout << ans;

    return 0;
}