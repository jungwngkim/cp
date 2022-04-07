#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char OP[] = { 'D', 'S', 'L', 'R' };

int D(int n) { return 2 * n % 10000; }
int S(int n) { return (n - 1 + 10000) % 10000;}
int L(int n) { return n * 10 % 10000 + n / 1000; }
int R(int n) { return n / 10 + n % 10 * 1000; }

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        
        queue<int> q;
        q.push(a);

        int p[10000], op[10000];
        p[a] = -2; op[a] = -1;
        memset(p, -1, sizeof(p));

        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            if(x == b) break;

            int y[] = { D(x), S(x), L(x), R(x) };
            
            for(int i = 0; i < 4; i++)
            {
                if(p[y[i]] == -1)
                {
                    p[y[i]] = x;
                    op[y[i]] = i;
                    q.push(y[i]);
                }
            }
        }

        string ans = "";
        int x = b;
        while(x != a)
        {
            ans = OP[op[x]] + ans;
            x = p[x];
        }
        cout << ans << '\n';
    }

    return 0;
}