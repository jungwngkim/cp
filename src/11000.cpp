#include <iostream>
#include <algorithm>

#define N 400000

using namespace std;

typedef pair<int, int> pi;

int n;
pi a[N];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < 2 * n; i += 2) 
    {
        cin >> a[i].first >> a[i + 1].first;
        a[i].second = 1;
        a[i + 1].second = -1;
    }

    sort(a, a + 2 * n);

    int ans = 0, s = 0;
    for(int i = 0; i < 2 * n;)
    {
        int j = i + 1;
        while(j < 2 * n && a[j].first == a[i].first && a[j].second == a[i].second)
        {
            j++;
        }

        if(a[i].second == 1)
        { 
            s += j - i;
            ans = max(ans, s);
        }
        else 
        {
            s -= j - i;
        }

        i = j;
    }

    cout << ans;
    
    return 0;
}