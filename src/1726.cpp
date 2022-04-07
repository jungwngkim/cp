#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

struct state { int y, x, r, cnt; };
struct dir { int dy, dx; };

int m, n;
int b[102][102];
bool used[102][102][5];
state s, t;
dir d[] = {
    {0, 0},
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int bfs()
{
    queue<state> q;
    q.push(s);
    used[s.y][s.x][s.r] = true;

    while(!q.empty())
    {
        state u = q.front();
        q.pop();

        if(u.y == t.y && u.x == t.x && u.r == t.r)
        {
            return u.cnt;
        }

        // Go
        for(int i = 1; i <= 3; i++)
        {
            state v = { u.y + d[u.r].dy * i, u.x + d[u.r].dx * i, u.r, u.cnt + 1 };
            if(b[v.y][v.x]) break;
            if(!used[v.y][v.x][v.r]) 
            {
                used[v.y][v.x][v.r] = true;
                q.push(v);
            }
        }

        // Turn
        if(u.r <= 2) 
        {
            if(!used[u.y][u.x][3]) 
            {
                used[u.y][u.x][3] = true;
                q.push({ u.y, u.x, 3, u.cnt + 1 });
            }
            if(!used[u.y][u.x][4]) 
            {
                used[u.y][u.x][4] = true;
                q.push({ u.y, u.x, 4, u.cnt + 1 });
            }
        }
        else
        {
            if(!used[u.y][u.x][1]) 
            {
                used[u.y][u.x][1] = true;
                q.push({ u.y, u.x, 1, u.cnt + 1 });
            }
            if(!used[u.y][u.x][2]) 
            {
                used[u.y][u.x][2] = true;
                q.push({ u.y, u.x, 2, u.cnt + 1 });
            }
        }
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> m >> n;

    for(int y = 0; y <= m + 1; y++) b[y][0] = b[y][n + 1] = 1;
    for(int x = 0; x <= n + 1; x++) b[0][x] = b[m + 1][x] = 1;
    
    for(int y = 1; y <= m; y++) for(int x = 1; x <= n; x++) cin >> b[y][x];
    
    cin >> s.y >> s.x >> s.r;
    s.cnt = 0;
    cin >> t.y >> t.x >> t.r;

    cout << bfs();

    return 0;
}