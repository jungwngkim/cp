#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int m, n, a[1001][1001];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int bfs()
{
    int depth = 0;
    bool visited[1001][1001];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q, nq;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (a[y][x] == 1)
                q.push({y, x});

    while (!q.empty())
    {   
        int cy = q.front().first, cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i], nx = cx + dx[i];
            if (ny < 0 || nx < 0)
                continue;
            if (a[ny][nx] == 0 && !visited[ny][nx])
            {
                nq.push({ny, nx});
                visited[ny][nx] = true;
            }
        }

        if (q.empty())
        {
            q.swap(nq);
            depth++;
        }
    }

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (a[y][x] == 0 && !visited[y][x])
                return -1;

    return depth - 1;
}

int main()
{
    scanf("%d %d", &m, &n);

    memset(a, -1, sizeof(a));
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            scanf("%d", &a[y][x]);
    printf("%d", bfs());
    return 0;
}