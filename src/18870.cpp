#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; 
    pair<int, int> a[1000000];
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        bool inc = true;
        if(i < n - 1 && (a[i].first == a[i + 1].first)) inc = false;
        a[i].first = idx;
        if(inc) idx++;
    }

    sort(a, a + n, [](auto & a, auto & b) { return a.second < b.second; });

    for(int i = 0; i < n; i++) cout << a[i].first << ' ';

    return 0;
}