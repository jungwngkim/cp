#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int adj[101][101], n;
void floyd_warshall()
{
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
void input()
{
    cin >> n; int m; cin >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) adj[i][j] = INF;
    for(int i = 1; i <= n; i++) adj[i][i] = 0;
    int u, v, w;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> w; adj[u][v] = min(adj[u][v], w);
    }
}
void output()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cout << (adj[i][j] == INF ? 0 : adj[i][j]) << ' ';
        cout << '\n';
    }  
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    input(); floyd_warshall(); output();
    return 0;
}