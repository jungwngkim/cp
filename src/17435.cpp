#include <iostream>

#define M 200000
#define K 20

using namespace std;

int f[M + 1][K];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> f[i][0];
    for(int j = 1; j < K; j++)
    {
        for(int i = 1; i <= m; i++)
        {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int n, x;
        cin >> n >> x;
        for(int j = 0; j < K; j++)
        {
            if(n & (1 << j))
            {
                x = f[x][j];
            }
        }
        cout << x << '\n';
    }
    
    return 0;
}