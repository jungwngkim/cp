#include <iostream>
#include <cstring>

using namespace std;

int n, m, a[14][14], dp[14 * 14][1 << 14];
int w[6][6] = {
    { 10, 8, 7, 5, 0, 1 },
    {  8, 6, 4, 3, 0, 1 },
    {  7, 4, 3, 2, 0, 1 },
    {  5, 3, 2, 2, 0, 1 },
    {  0, 0, 0, 0, 0, 0 },
    {  1, 1, 1, 1, 0, 0 },    
};

int calc(int i, int b)
{
    if(i >= n * m) return 0;

    if(dp[i][b] != -1) return dp[i][b];

    int &ans = dp[i][b];
    ans = calc(i + 1, b >> 1);

    if(!(b & 1))
    {
        if(i / m < n - 1) 
            ans = max(ans, calc(i + 1, (b | (1 << m)) >> 1) + w[a[i / m][i % m]][a[i / m + 1][i % m]]);
        if((i % m < m - 1) && !(b & 2)) 
            ans = max(ans, calc(i + 2, b >> 2) + w[a[i / m][i % m]][a[i / m][i % m + 1]]);
    }

    return ans;
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    {
        char c;
        cin >> c;
        a[i][j] = c - 'A';
    }

    cout << calc(0, 0);
    
    return 0;
}