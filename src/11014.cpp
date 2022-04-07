#include <iostream>
#include <vector>
#include <cstring>

#define N 80
#define u(y, x) ((y * 80) + x)

using namespace std;

int t, n, m, bcnt, cnt;
bool b[N][N];
int dy[] = { -1, 0, 1, -1, 0, 1 }, dx[] = { -1, -1, -1, 1, 1, 1 };

int mt[N * N];
bool visited[N * N];
vector<int> adj[N * N];

bool dfs(int u)
{
    for(int v : adj[u])
    {
        if(!visited[v] && mt[v] == -1)
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
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--)
    {
        for(vector<int> adj_i : adj) adj_i.clear();

        cin >> n >> m;

        int bcnt = 0;
        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < m; x++)
            {
                char c;
                cin >> c;
                b[y][x] = (c == '.');
                if(b[y][x]) bcnt++;
            }
        }

        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < m; x += 2)
            {
                if(!b[y][x]) continue;
                for(int i = 0; i < 6; i++)
                {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if(!b[ny][nx]) continue;
                    adj[u(y, x)].push_back(u(ny, nx));
                }
            }
        }

        memset(mt, -1, sizeof(mt));
        int cnt = 0;
        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < m; x += 2)
            {
                if(!b[y][x]) continue;
                memset(visited, false, sizeof(visited));
                if(dfs(u(y, x))) cnt++;
            }
        }

        cout << bcnt - cnt << '\n';
    }
    
    return 0;
}