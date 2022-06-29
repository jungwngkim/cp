#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int n, k;
ll ans;
vector<pi> a;
vector<int> c;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    a.resize(n);
    c.resize(k);

    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for(int i = 0; i < k; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    priority_queue<int> pq;
    for(int i = 0, j = 0; i < k; i++)
    {
        while(j < n && a[j].first <= c[i]) pq.push(a[j++].second);

        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;

    return 0;
}