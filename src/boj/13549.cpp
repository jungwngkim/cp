#include <iostream>
#include <queue>
#include <cstring>

#define N 100001

using namespace std;

typedef pair<int, int> pi;

int s, t;
int d[N];

void dijkstra()
{
    deque<pi> q;
    q.push_back({ s, 0 });

    memset(d, 0x3f, sizeof(d));
    d[s] = 0;

    while(!q.empty())
    {
        int u = q.front().first, d_u = q.front().second;
        q.pop_front();

        if(d[u] != d_u) continue;

        if(u * 2 <= 100000 && d[u * 2] > d_u)
        {
            d[u * 2] = d_u;
            q.push_front({ u * 2, d[u * 2] });
        }

        if(u + 1 <= 100000 && d[u + 1] > d_u + 1)
        {
            d[u + 1] = d_u + 1;
            q.push_back({ u + 1, d[u + 1] });
        }

        if(u - 1 >= 0 && d[u - 1] > d_u + 1)
        {
            d[u - 1] = d_u + 1;
            q.push_back({ u - 1, d[u - 1] });
        }
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> s >> t;
    dijkstra();
    cout << d[t];
    
    return 0;
}