#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int n, m;
int c[502][502], d[502][502];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int ans[502];

void dijk(int s)
{
    memset(d, 0x3f, sizeof(d));
    d[s][1] = 0;

    priority_queue<pii> pq;
    pq.push({ 0, { s, 1 } });

    while(!pq.empty())
    {
        int d_xy = -pq.top().first;
        int y = pq.top().second.first, x = pq.top().second.second;
        pq.pop();

        if(d_xy > d[y][x]) continue;
        if(x == m) 
        {
            ans[y]++;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if(d[ny][nx] > d_xy + c[ny][nx]) 
            {
                d[ny][nx] = d_xy + c[ny][nx];
                pq.push({ -d[ny][nx], { ny, nx } });
            }
        }
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    memset(c, 0x3f, sizeof(c));

    cin >> n >> m;

    for(int y = 1; y <= n; y++)
        for(int x = 1; x <= m; x++)
            cin >> c[y][x];
    
    for(int y = 1; y <= n; y++)
        dijk(y);

    for(int y = 1; y <= n; y++) cout << ans[y] << '\n';

    return 0;
}