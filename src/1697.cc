#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    queue<pair<int, int>> q;
    q.push({n, 0});

    bool visited[100001];
    memset(visited, false, sizeof(visited));
    visited[n] = true;

    while (!q.empty())
    {
        int curr = q.front().first;
        int time = q.front().second;
        q.pop();

        if (curr == k)
        {
            printf("%d", time);
            break;
        }

        if (curr + 1 <= 100000 && !visited[curr + 1])
        {
            visited[curr + 1] = true;
            q.push({curr + 1, time + 1});
        }
        if (curr - 1 >= 0 && !visited[curr - 1])
        {
            visited[curr - 1] = true;
            q.push({curr - 1, time + 1});
        }
        if (curr * 2 <= 100000 && !visited[curr * 2])
        {
            visited[curr * 2] = true;
            q.push({curr * 2, time + 1});
        }
    }

    return 0;
}