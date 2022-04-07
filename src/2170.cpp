#include <iostream>
#include <algorithm>

#define N 1000000

using namespace std;

typedef pair<int, int> pi;

int n;
pi a[N];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int lo, hi, sum = 0;
    for(int i = 0; i < n; i++)
    {
        lo = a[i].first, hi = a[i].second;
        while(i + 1 < n && hi >= a[i + 1].first)
        {
            hi = max(hi, a[i + 1].second);
            i++;
        }
        sum += hi - lo;
    }
    cout << sum;
    
    return 0;
}