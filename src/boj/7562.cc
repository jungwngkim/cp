#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dx[] = {1, -1, 2, -2, 2, -2, 1, -1};
int n, sy, sx, fy, fx;

int bfs()
{
    int board[300][300];
    memset(board, -1, sizeof(board));
    board[sy][sx] = 0;

    queue<pair<int, int>> q;
    q.push({sy, sx});

    while (!q.empty())
    {
        int cy = q.front().first, cx = q.front().second;
        q.pop();

        if (cy == fy && cx == fx) break;

        for (int i = 0; i < 8; i++)
        {
            int ny = cy + dy[i], nx = cx + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;

            if (board[ny][nx] == -1)
            {
                board[ny][nx] = board[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }

    return board[fy][fx];
}
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d%d%d%d", &n, &sy, &sx, &fy, &fx);
        printf("%d\n", bfs());
    }
    return 0;
}