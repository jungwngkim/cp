#include <iostream>

using namespace std;

const int N = 5000;

int n, k;
int tree[2 * N];

void insert(int idx) {
    idx += n;
    for (; idx >= 1; idx /= 2) tree[idx]++;
}

int calc(int x) {
    int idx = 1;
    while (idx < n) {
        tree[idx]--;
        idx *= 2;
        if (tree[idx] < x) {
            x -= tree[idx];
            idx++;
        }
    }
    tree[idx]--;
    return idx - n;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int x;
    cin >> n >> k;
    cout << '<';

    x = k;
    for (int i = n - 1; i >= 1; i++) {
        cout << calc(x) << ", ";
        x = (x + k - 1) % i;
        if(!x) x = 1;
    }

    return 0;
}