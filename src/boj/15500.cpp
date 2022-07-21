#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, pos[124];
stack<int> s[2];
vector<pair<int, int>> ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0, t; i < n; i++)
    {
        cin >> t;
        s[0].push(t);
        pos[t] = 0;
    }

    for (int i = n; i >= 1; i--)
    {
        while (s[pos[i]].top() != i)
        {
            ans.push_back({pos[i] + 1, (pos[i] ^ 1) + 1});
            s[(pos[i] ^ 1)].push(s[pos[i]].top());
            pos[s[pos[i]].top()] = (pos[i] ^ 1);
            s[pos[i]].pop();
        }
        ans.push_back({pos[i] + 1, 3});
        s[pos[i]].pop();
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
    {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}