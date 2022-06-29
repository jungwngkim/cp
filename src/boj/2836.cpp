#include <iostream>
#include <algorithm>

#define N 300000

using namespace std;

int n, idx;
long long m;
pair<int, int> a[N];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int from, to;
        cin >> from >> to;
        if(to < from) a[idx++] = { to, from };
    }
    
    sort(a, a + idx);

    int lo, hi, sum = 0;
    for(int i = 0; i < idx; i++)
    {
        lo = a[i].first, hi = a[i].second;
        while(i + 1 < idx && a[i + 1].first <= hi)
        {
            i++;
            hi = max(hi, a[i].second);
        }
        sum += hi - lo;
    }

    cout << m + 2 * sum;
    
    return 0;
}