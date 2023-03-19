#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int a[100];

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int gcd_all = 0;
    for (int i = 1; i < n; i++) {
        gcd_all = gcd(a[i] - a[i - 1], gcd_all);
    }

    for(int i = 2; i <= gcd_all / 2; i++) {
        if(!(gcd_all % i)) cout << i << ' ';
    }
    cout << gcd_all;

    return 0;
}