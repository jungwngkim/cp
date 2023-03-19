#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n, ans = -1;
    cin >> n;
    for (int i = 0; i <= min(n, 27LL); i += 3) {
        if ((n - i) % 5 == 0) {
            ans = i;
            break;
        }
    }

    if (ans == -1) {
        printf("-1");
    } else {
        printf("%lld", ans / 3 + (n - ans) / 5);
    }

    return 0;
}
