#include <stdio.h>
#include <vector>

using namespace std;

int v, e;
vector<vector<int>> edge;
vector<int> visited;

void dfs(int from, int check)
{
    visited[from] = check;
    for (int to : edge[from])
        if (visited[to] == -1)
            dfs(to, (check + 1) % 2);
}

bool solve()
{
    for (int from = 0; from < v; from++)
        if (visited[from] == -1)
            dfs(from, 0);

    for (int from = 0; from < v; from++)
        for (int to : edge[from])
            if (visited[to] == visited[from])
                return false;

    return true;
}

void init()
{
    scanf("%d %d", &v, &e);

    edge = vector<vector<int>>(v);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        edge[from - 1].push_back(to - 1);
        edge[to - 1].push_back(from - 1);
    }
    visited = vector<int>(v, -1);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        init();
        printf("%s\n", solve() ? "YES" : "NO");
    }

    return 0;
}