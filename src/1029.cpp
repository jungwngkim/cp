#include <iostream>

#define N 16

using namespace std;

int n, ans;
int w[N][N];
bool visited[N];

void dfs(int u, int p, int cnt)
{
    int ccnt = 0;
    for(int v = 1; v <= n; v++)
    {
        if(v == u) continue;

        if(!visited[v] && w[u][v] >= w[p][u]) 
        {
            ccnt++;
            visited[v] = true;
            dfs(v, u, cnt + 1);
            visited[v] = false;
        }
    }
    
    if(!ccnt)
    {
        ans = max(ans, cnt);
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        char c; 
        cin >> c;
        w[i][j] = c - '0';
    }

    visited[1] = true;
    dfs(1, 0, 1);

    cout << ans;
    
    return 0;
}