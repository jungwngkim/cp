#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[50];
bool dp[500001];
long long bdp[500001];
vector<int> b, c;
int n, ans;

bool uniq(int a1, int a2)
{
    return !(bdp[a1] & bdp[a2]);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    dp[0] = true;
    b.push_back(0);
    for(int i = 0; i < n; i++)
    {
        for(int &b_i : b)
        {
            if(dp[a[i] + b_i]) 
            {
                ans = max(ans, a[i] + b_i);
            }
            else
            {
                if(uniq(a[i], b_i))
                {
                    dp[a[i] + b_i] = true;
                    c.push_back(a[i] + b_i);
                }
            }
        }
        b.insert(b.end(), c.begin(), c.end());
        c.clear();
    }

    if(ans) cout << ans;
    else cout << -1;
    
    return 0;
}