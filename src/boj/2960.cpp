#include <iostream>

using namespace std;

bool no_prime[1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        if (!no_prime[i]) {
            if (!(--k)) {
                printf("%d", i);
                exit(0);
            }

            for (int j = i * 2; j <= n; j += i) {
                if (!no_prime[j]) {
                    no_prime[j] = true;
                    if (!(--k)) {
                        printf("%d", j);
                        exit(0);
                    }
                }
            }
        }
    }

    return 0;
}