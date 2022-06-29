#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;
long long a[300000], b[300000], dp[300000];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    bool cont;
    int m = 0;
    for(int i = 0; i < n;) {
        int j = i;
        long long max_pt = 0;
        while(s[j] == s[i]) {
            if(j == 0 || j == n - 1) cont = true;
            max_pt = max(max_pt, a[j]);
            j++;
        }

        if(cont) {
            cont = false;
            i = j;
            continue;
        }

        b[m] = max_pt;
        m++;
        i = j;
    }

    sort(b, b + m, [](const int &a, const int &b) { return a > b; });

    long long ans = 0;
    for(int i = 0; i < (m + 1) / 2; i++) ans += b[i];
    cout << ans;
    
    return 0;
}