#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 1000000000

using namespace std;

vector<int> a;

void precalc() {
    int s = 0;
    for (int i = 3; s + i < 2 * MAXN; i++)
    {
        a.push_back(s + i);
        s += a.back();
    }
}

char calc(int n) {
    if (n == 0) return 'm';

    while (n > 0) {
        int idx = lower_bound(a.begin(), a.end(), n) - a.begin();
        if (n == a[idx]) return 'm';
        if (idx == 0) break;


        n -= a[idx - 1];
        if (n % a[idx - 1] == 0) return 'o';
    }
    return 'o';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    precalc();

    int n;
    cin >> n;
    cout << calc(n - 1);

    return 0;
}
