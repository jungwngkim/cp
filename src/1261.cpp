#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> pii;

int n, m;
int d[100][100], map[100][100];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };

void dijkstra()
{
    deque<pii> q;
    q.push_back({ 0, { 0, 0 } });

    memset(d, 0x3f, sizeof(d));
    d[0][0] = 0;

    while(!q.empty())
    {
        int d_yx = q.front().first, y = q.front().second.first, x = q.front().second.second;
        q.pop_front();

        if(d_yx > d[y][x]) continue;

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(d[ny][nx] > d_yx + map[ny][nx])
            {
                d[ny][nx] = d_yx + map[ny][nx];
                if(map[ny][nx]) q.push_back({ d[ny][nx], { ny, nx } });
                else q.push_front({ d[ny][nx], { ny, nx } });
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n;
    for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) 
    {
        char c; 
        cin >> c; 
        map[y][x] = c - '0';
    }

    dijkstra();
    cout << d[n-1][m-1];
    
    return 0;
}