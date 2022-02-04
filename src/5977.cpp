#include <iostream>
#include <deque>

#define N 100001

using namespace std;

typedef long long ll;

int n, k;
ll a[N], dp[N], s;
deque<ll> dq;

ll c(int i)
{
    return a[i] + dp[i - 1];
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        s += a[i];
    }

    for(int i = 1; i <= k; i++)
    {
        while(!dq.empty() && c(dq.back()) > c(i)) dq.pop_back();
        dq.push_back(i);
        dp[i] = 0;
    }

    for(int i = k + 1; i <= n; i++)
    {
        while(!dq.empty() && c(dq.back()) > c(i)) dq.pop_back();
        dq.push_back(i);
        if(!dq.empty() && dq.front() == i - k - 1) dq.pop_front();
        dp[i] = c(dq.front());
    }

    cout << s - dp[n];
    
    return 0;
}