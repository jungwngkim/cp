#include <iostream>
#include <cstring>

#define N 2501

using namespace std;

int dp[N], d1[N], d2[N];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s;
    cin >> s;
    n = s.length();

    s = "*" + s;

    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    memset(dp, 0x3f, sizeof(dp));

    dp[0] = 0;
    for(int right = 1; right <= n; right++)
    {
        for(int mid = right; mid >= right / 2 + 1; mid--)
        {
            int left = 2 * mid - right;

            if(d1[mid] == right - mid && s[left] == s[right])
            {
                d1[mid]++;
                dp[right] = min(dp[right], dp[left - 1] + 1);
            }

            left--;
            if(d2[mid] == right - mid && s[left] == s[right])
            {
                d2[mid]++;
                dp[right] = min(dp[right], dp[left - 1] + 1);
            }
        }
    }
    cout << dp[n];

    return 0;
}