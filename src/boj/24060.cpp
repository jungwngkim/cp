#include <iostream>

using namespace std;

int A[500001], tmp[500001], cnt, ans = -1, n, k;

void _merge(int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;

    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];

    i = p;
    t = 1;
    while (i <= r) {
        cnt++;
        if (cnt == k) ans = tmp[t];
        // cout << "Save: " << tmp[t] << ' ' << '\n';
        A[i++] = tmp[t++];
    }
}

void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) >> 1;
        // cout << p << ' ' << r << ' ' << q << ' ' << '\n';
        merge_sort(p, q);
        merge_sort(q + 1, r);
        _merge(p, q, r);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> A[i];
    merge_sort(1, n);
    cout << ans;

    return 0;
}
