#include <iostream>

#define N 100000
#define K 17
#define INF 0x3f3f3f3f

using namespace std;

int st[N][K], lg[N + 1], f[N];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    long long m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> f[i] >> st[i][0];
    }

    // RMQ
    lg[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for(int j = 1; j < K; j++)
    {
        for(int i = 0; i + (1 << j) < n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    // Two pointers
    int lo = 0, hi = 0, ans = INF;
    long long t = 0;
    while(hi <= n)
    {
        if(t < m)
        {
            t += f[hi++];
        }
        else
        {
            int j = lg[hi - lo];
            ans = min(ans, max(st[lo][j], st[hi - (1 << j)][j]));
            t -= f[lo++];
        }
    }
    cout << ans;
    
    return 0;
}