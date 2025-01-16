#include <iostream>
#include <vector>

using namespace std;

int k, a[1024];
vector<int> v[11];

int pow(int n) {
    int res = 1;
    for(int i = 0; i < n; i++) res *= 2;
    return res;
}

void calc(int l, int r, int d) {
    if(l <= r) {
        int m = (l + r) >> 1;
        v[d].push_back(a[m]);
        calc(l, m - 1, d + 1);
        calc(m + 1, r, d + 1);
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> k;
    for(int i = 0; i < pow(k) - 1; i++) {
        cin >> a[i];
    }

    calc(0, pow(k) - 1, 0);

    for(int d = 0; d < k; d++) {
        for(int x : v[d]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}