#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;

    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        int d[1001], ans = -1;
        memset(d, -1, sizeof(d));

        for(int i = 0; i < n; i++)
        {
            stack<int> st;
            st.push(-1);

            for(int j = 0; j < m; j++)
            {
                int t; cin >> t;
                if(t == 0) d[j] = i;
            }
            d[m] = i + 1;

            for(int right = 0; right <= m; right++)
            {
                while(st.size() > 1 && d[right] > d[st.top()])
                {
                    int mid = st.top(); st.pop();
                    int left = st.top();
                    ans = max(ans, (right - left - 1) * (i - d[mid]));
                }
                st.push(right);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}