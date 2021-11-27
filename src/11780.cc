#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int d[101][101], p[101][101];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    memset(d, 0x3f, sizeof(d));
    memset(p, -1, sizeof(p));
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) 
            cout << (d[i][j] == INF ? 0 : d[i][j]) << ' ';
        cout << '\n';
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j || d[i][j] == INF) 
                cout << 0 << '\n';
            else
            {   
                stack<pair<int, int>> s;
                vector<int> v;

                s.push({i, j});
                v.push_back(i);

                while(!s.empty())
                {
                    int s_i = s.top().first;
                    int s_j = s.top().second;

                    s.pop();

                    int s_k = p[s_i][s_j];

                    if(s_k == -1)
                    {
                        v.push_back(s_j);
                    }
                    else
                    {
                        s.push({s_k, s_j});
                        s.push({s_i, s_k});
                    }
                }

                cout << v.size() << ' ';
                for(int v_i : v)
                    cout << v_i << ' ';
                cout << '\n';
            }
        }
    }


    return 0;
}