#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int a[1001][1001], n, m;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

struct point
{
    int y, x, depth;
    bool wall_break;
};

int bfs()
{
    bool visited[1001][1001][2];
    memset(visited, false, sizeof(visited));
    visited[0][0][0] = true;

    queue<point> q;
    q.push({0, 0, 1, false});

    while (!q.empty())
    {
        int cy = q.front().y, cx = q.front().x, cdepth = q.front().depth;
        bool c_wall_break = q.front().wall_break;

        q.pop();

        if (cy == n - 1 && cx == m - 1)
            return cdepth;

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i], nx = cx + dx[i];
            if (ny == -1 || nx == -1 || ny == n || nx == m)
                continue;

            if (c_wall_break)
            {
                if (a[ny][nx] == 0 && !visited[ny][nx][1])
                {
                    q.push({ny, nx, cdepth + 1, true});
                    visited[ny][nx][1] = true;
                }
            }
            else
            {
                if (a[ny][nx] == 0 && !visited[ny][nx][0])
                {
                    q.push({ny, nx, cdepth + 1, false});
                    visited[ny][nx][0] = true;
                }

                if (a[ny][nx] == 1 && !visited[ny][nx][1])
                {
                    q.push({ny, nx, cdepth + 1, true});
                    visited[ny][nx][1] = true;
                }
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    char t;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            cin >> t, a[y][x] = t - '0';

    printf("%d", bfs());

    return 0;
}