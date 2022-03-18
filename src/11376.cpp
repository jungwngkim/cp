#include <iostream>

using namespace std;

int n, m;
int c[2002][2002];
vector<vector<int>> adj;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    adj.resize(n + m + 2);

    for(int i = 1; i <= n; i++)
    {
        c[0][i] = 2;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
    return 0;
}