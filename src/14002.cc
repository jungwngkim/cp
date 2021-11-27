#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> L[1001];
int l[1001], len, ans_a;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    
    int a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        auto pos = lower_bound(l + 1, l + len + 1, a);
        *pos = a;

        L[a] = L[l[pos - l - 1]];
        L[a].push_back(a);

        if(pos == l + len + 1) 
        { 
            len++;
            ans_a = a;
        }
    }

    cout << len << '\n';
    for(int ans_i : L[ans_a]) cout << ans_i << ' ';

    return 0;
}