#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int height[501][501], cost[501][501], m, n, dx[] = {-1, 0, 0, 1}, dy[] = {0, 1, -1, 0};
pair<int, pair<int, int>> height_map[250000];

int main()
{
    scanf("%d %d", &m, &n);

    memset(height, 0x3f, sizeof(height));

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%d", &height[y][x]);
            height_map[n * y + x] = {height[y][x], {y, x}};
        }
    }

    sort(height_map, height_map + m * n - 1);

    cost[m - 1][n - 1] = 1;
    for (int i = 0; i < m * n - 1; i++)
    {
        int cost_sum = 0;
        int cy = height_map[i].second.first, cx = height_map[i].second.second, ch = height_map[i].first;
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i], nx = cx + dx[i];
            if(ny < 0 || nx < 0) continue;
            if (ch > height[ny][nx])
            {
                cost_sum += cost[ny][nx];
            }
        }
        cost[cy][cx] = cost_sum;
    }
    printf("%d", cost[0][0]);

    return 0;
}

/*
모든 점을 입력받은 뒤, {height, y, x} 이거의 배열을 높이 순서대로 정렬한다. 
높이가 제일 작은 점이 끝점이 아니면 종료한다. 
높이가 작은 순서대로 자신의 옆에 있는 자신보다 작은 점들의 cost를 더해서 자신한테 할당한다. 
마지막에 cost[0][0]을 출력한다.
*/