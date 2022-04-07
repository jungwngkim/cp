#include <iostream>
#include <cstring>

#define N 10001

using namespace std;

int a1[N], a2[N];
int n, dp[N][10];

void calc(int i, int inc)
{    
    int c1 = (a1[i] + inc) % 10, c2 = a2[i];

    if(dp[i][inc] != -1)
    {
        return;
    }

    int linc = (c2 - c1 + 10) % 10, rinc = (c1 - c2 + 10) % 10;
    
    if(i == n - 1)
    {
        dp[i][inc] = min(linc, rinc);
    }
    else
    {
        calc(i + 1, (inc + linc) % 10);
        calc(i + 1, inc);
        
        dp[i][inc] = min(
            linc + dp[i + 1][(inc + linc) % 10], 
            rinc + dp[i + 1][inc]
        );
    }
}

void backtrack(int i, int inc)
{
    int c1 = (a1[i] + inc) % 10, c2 = a2[i];
    int linc = (c2 - c1 + 10) % 10, rinc = (c1 - c2 + 10) % 10;
    if(i == n - 1)
    {
        cout << i + 1 << ' ' << (linc < rinc ? linc : -rinc) << '\n'; 
    }
    else
    {
        if(linc + dp[i + 1][(inc + linc) % 10] < rinc + dp[i + 1][inc])
        {
            cout << i + 1 << ' ' << linc << '\n';
            backtrack(i + 1, (inc + linc) % 10);
        }
        else
        {
            cout << i + 1 << ' ' << -rinc << '\n';
            backtrack(i + 1, inc);
        }
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        char c; 
        cin >> c;
        a1[i] = c - '0';
    }
    for(int i = 0; i < n; i++)
    {
        char c; 
        cin >> c;
        a2[i] = c - '0';
    }

    calc(0, 0);
    cout << dp[0][0] << '\n';
    backtrack(0, 0);

    return 0;
}