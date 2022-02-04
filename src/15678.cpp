#include <iostream>
#include <deque>

#define N 100001
#define INF 1000000000

using namespace std;

typedef long long ll;

int n, k;
ll dp[N], a[N], ans = -INF;
deque<int> dq;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = a[1];
    ans = max(ans, dp[1]);
    dq.push_back(1);

    for(int i = 2; i <= k + 1; i++)
    {
        dp[i] = max(0LL, dp[dq.front()]) + a[i];
        ans = max(ans, dp[i]);
        while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
        dq.push_back(i);
    }

    for(int i = k + 2; i <= n; i++)
    {
        if(!dq.empty() && dq.front() == i - k - 1) dq.pop_front();
        dp[i] = max(0LL, dp[dq.front()]) + a[i];
        ans = max(ans, dp[i]);
        while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
        dq.push_back(i);
    }

    cout << ans;
    
    return 0;
}