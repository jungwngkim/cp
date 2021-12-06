#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Init to zero
int board[12][12], label[12][12];
int dx[] = { -1, 0, 0, 1 }, dy[] = { 0, -1, 1, 0 };

// Disjoint set union for Kruskal's algorithm
int p[7], s[7];
void create(int x)
{
    p[x] = x;
    s[x] = 1;
}

int find(int x)
{
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    if(s[a] < s[b]) swap(a, b);
    p[b] = a;
    s[a] += s[b];
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int y = 1; y <= n; y++) for(int x = 1; x <= m; x++) cin >> board[y][x];
    
    // find all islands and label each with integers
    int island_cnt = 0;
    for(int y = 1; y <= n; y++) for(int x = 1; x <= m; x++)
    {
        if(board[y][x] && !label[y][x])
        {
            island_cnt++;
            queue<pair<int, int>> q;
            q.push({y, x});

            label[y][x] = island_cnt;

            while(!q.empty())
            {
                int cy = q.front().first, cx = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++)
                {
                    int ny = cy + dy[i], nx = cx + dx[i];
                    if(board[ny][nx] && !label[ny][nx])
                    {
                        label[ny][nx] = island_cnt;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    // find all avaliable 'bridges'
    // by iterating over the rows and columns
    vector<pair<int, pair<int, int>>> adj;

    // rows
    int l, r;
    for(int y = 1; y <= n; y++) 
    {
        l = r = 0;
        for(int x = 1; x <= m; x++)
        {
            if(label[y][x])
            {
                if(r - l > 1) adj.push_back({ r - l, { label[y][l], label[y][x] } });
                l = r = x;
            }
            else if(l) r++;
        }
    }

    // columns
    int t, b;
    for(int x = 1; x <= m; x++)
    {
        t = b = 0;
        for(int y = 1; y <= n; y++)
        {
            if(label[y][x])
            {
                if(b - t > 1) adj.push_back({ b - t, { label[t][x], label[y][x] } });
                t = b = y;
            }
            else if(t) b++;
        }
    }

    sort(adj.begin(), adj.end());

    for(int i = 1; i <= island_cnt; i++) create(i);

    // Kruskal's algorithm
    int cnt = 0, sum = 0;
    for(auto edge : adj)
    {
        if(cnt >= island_cnt - 1) break;
        int u = edge.second.first, v = edge.second.second, w = edge.first;

        u = find(u); v = find(v);
        if(u != v)
        {
            merge(u, v);
            sum += w;
            cnt++;
        }
    }

    if(cnt < island_cnt - 1) cout << -1;
    else cout << sum;

    return 0;
}