#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

bool adj[1001][1001];
int n, m, v;

void dfs()
{
    bool visited[1001];
    memset(visited, false, sizeof(visited));

    stack<int> s;
    s.push(v);

    while (!s.empty())
    {
        int c = s.top();
        s.pop();

        if (!visited[c])
        {
            visited[c] = true;
            printf("%d ", c);
            for (int i = n; i >= 1; i--)
            {
                if (adj[c][i] && !visited[i])
                    s.push(i);
            }
        }
    }
}

void bfs()
{
    bool visited[1001];
    memset(visited, false, sizeof(visited));
    visited[v] = true;

    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int c = q.front();
        q.pop();

        printf("%d ", c);

        for (int i = 1; i <= n; i++)
        {
            if (adj[c][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &v);

    int vi, vo;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &vi, &vo);
        adj[vi][vo] = adj[vo][vi] = true;
    }

    dfs();
    printf("\n");
    bfs();

    return 0;
}