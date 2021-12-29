#include <iostream>
#include <vector>
#include <cstring>

#define N 10000
#define K 14

using namespace std;

pair<int, int> euler_st[2 * N - 1][K];
int n, euler_idx[N + 1], lg[2 * N];
vector<int> adj[N + 1];
bool is_root[N + 1];

void dfs(int u, int depth, int &idx)
{
    euler_st[idx][0] = { depth, u };
    euler_idx[u] = idx;
    idx++;

    for(int v : adj[u])
    {
        dfs(v, depth + 1, idx);

        euler_st[idx][0] = { depth, u };
        idx++;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    lg[1] = 0;
    for(int i = 2; i <= 2 * N - 1; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    int t;
    cin >> t;

    while(t--)
    {
        memset(is_root, true, sizeof(is_root));

        cin >> n;
        for(int x = 1; x <= n; x++) 
        {
            adj[x].clear();
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            is_root[v] = false;
            adj[u].push_back(v);
        }

        int root;
        for(int x = 1; x <= n; x++) 
        {
            if(is_root[x]) 
            {
                root = x;
                break;
            }
        }
        
        int idx = 0;
        dfs(root, 1, idx);
        
        // build rmq
        for(int j = 1; j < K; j++)
        {
            for(int i = 0; i + (1 << j) < 2 * n - 1; i++)
            {
                euler_st[i][j] = min(euler_st[i][j - 1], euler_st[i + (1 << (j - 1))][j - 1]);
            }
        }

        // answer rmq
        {
            int u, v;
            cin >> u >> v;
            u = euler_idx[u], v = euler_idx[v];
            if(u > v) swap(u, v);

            int j = lg[v - u + 1];
            cout << min(euler_st[u][j], euler_st[v - (1 << j) + 1][j]).second << '\n';
        }
    }
    
    return 0;
}
