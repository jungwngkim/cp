#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l[1000001], l_i[1000001], a[1000001], p_i[1000001], len, ans_i;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        auto pos = lower_bound(l + 1, l + len + 1, a[i]);
        *pos = a[i];
        l_i[pos - l] = i;
        p_i[i] = l_i[pos - l - 1];

        if(pos == l + len + 1)
        {
            len++;
            ans_i = i;
        }
    }

    cout << len << '\n';
    vector<int> ans;
    while(ans_i != 0)
    {
        ans.push_back(a[ans_i]);
        ans_i = p_i[ans_i];
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << ' ';

    return 0;
}