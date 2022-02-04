#include <iostream>
#include <algorithm>

#define N 50

using namespace std;

int n;
pair<int, int> a[N];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i].first;
        a[i].second = i;    
    }

    sort(a, a + n);

    for(int i = 0; i < n; i++) 
    {
        a[i].first = a[i].second;
        a[i].second = i;    
    }

    sort(a, a + n);

    for(int i = 0; i < n; i++) cout << a[i].second << ' ';

    return 0;
}