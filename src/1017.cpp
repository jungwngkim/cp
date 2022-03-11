#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> a, ans;
bool is_prime[2001];

int mt_cnt, mt[50];
bool visited[50];
vector<int> adj[50];

void build_prime()
{
    memset(is_prime, true, sizeof(is_prime));

    for(int i = 2; i * i <= 2000; i++)
        if(is_prime[i])
            for(int j = i * i; j <= 2000; j += i)
                is_prime[j] = false;
}

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

    build_prime();

    cin >> n;
    a.resize(n);
    for(int &x : a)
    {
        cin >> x;
    }

    for(int i = 1; i < n; i++)
    {
        if(is_prime[a[0] + a[i]])
        {
            for(int u = 1; u < n; u++)
            {
                if(u == i) continue;
                adj[u].clear();
            }
            
            memset(mt, 0, sizeof(mt));
            mt_cnt = 0;

            for(int u = 1; u < n; u++)
            {
                if(u == i) continue;
                for(int v = 1; v < n; v++)
                {
                    if(v == i) continue;
                    if(is_prime[a[u] + a[v]]) adj[u].push_back(v);
                }
            }

            for(int u = 1; u < n; u++)
            {
                if(u == i) continue;
                memset(visited, false, sizeof(visited));
                if(dfs(u)) mt_cnt++;
            }

            if(mt_cnt == n - 2) 
            {
                ans.push_back(a[i]);
            }
        }
    }

    if(ans.size()) 
    {
        sort(ans.begin(), ans.end());
        for(int x : ans)
        {
            cout << x << ' ';
        }
    }
    else
    {
        cout << -1;
    }
    
    return 0;
}