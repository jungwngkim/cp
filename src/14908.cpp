#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1001], t[1001], s[1001];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        a[i] = i;
        cin >> t[i] >> s[i];
    }

    sort(a + 1, a + n + 1, [](const int &i, const int &j) {
        if(s[i] * t[j] == s[j] * t[i]) return i < j;
        else return s[i] * t[j] > s[j] * t[i];
    });

    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    
    return 0;
}