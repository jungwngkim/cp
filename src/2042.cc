#include <iostream>

using namespace std;

int n, m, k;
long long t[1000001], a[1000001];

long long sum(int i) {
    long long s = 0;
    while(i >= 1) {
        s += t[i];
        i -= i & -i;
    }
    return s;
}

long long sum(int i, int j) {
    return sum(j) - sum(i - 1);
}

void add(int i, long long delta) {
    while(i <= n) {
        t[i] += delta;
        i += i & -i;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }

    int op;
    long long x, y;
    for(int i = 0; i < (m + k); i++) {
        cin >> op >> x >> y;
        if(op == 1) {
            add(x, y - a[x]);
            a[x] = y;
        }
        else {
            cout << sum(x, y) << '\n';
        }
    }

    return 0;
}