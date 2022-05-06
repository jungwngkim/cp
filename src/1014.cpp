#include <iostream>
#include <cstring>
#include <vector>

#define u(y, x) (y * 10 + x)

using namespace std;

int t, n, m, cnt1, cnt2;
int b[10][10];

int dy[] = { -1, 0, 1, -1, 0, 1 }, dx[] = { -1, -1, -1, 1, 1, 1 };

int mt[100];
bool visited[100];
vector<int> adj[100];

int dfs(int u)
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
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--)
    {
        cnt1 = cnt2 = 0;
        memset(mt, -1, sizeof(mt));

        cin >> n >> m;
        for(int y = 0; y < n; y++) for(int x = 0; x < m; x++)
        {
            char c;
            cin >> c;
            b[y][x] = c == '.';
            if(b[y][x]) cnt1++;
        }

        for(int y = 0; y < n; y++) for(int x = 0; x < m; x += 2)
        {
            if(!b[y][x]) continue;
            adj[u(y, x)].clear();

            for(int i = 0; i < 6; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(!b[ny][nx]) continue;
                adj[u(y, x)].push_back(u(ny, nx));
            }
        }

        for(int y = 0; y < n; y++) for(int x = 0; x < m; x += 2)
        {
            if(!b[y][x]) continue;
            memset(visited, false, sizeof(visited));
            if(dfs(u(y, x))) cnt2++;
        }

        cout << cnt1 - cnt2 << '\n';
    }
    
    return 0;
}