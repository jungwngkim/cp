#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n;
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n;
    for(int i = 0, t; i < n; i++)
    {
        cin >> t;
        q.push(t);
    }

    int ans = 0;
    for(int i = 1, t1, t2; i < n; i++)
    {
        t1 = q.top(); q.pop();
        t2 = q.top(); q.pop();
        ans += t1 + t2;
        q.push(t1 + t2);
    }
    cout << ans;
    
    return 0;
}