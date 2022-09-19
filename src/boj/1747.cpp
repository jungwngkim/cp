#include <iostream>
#include <vector>

#define N 1003002

using namespace std;

vector<int> p;
bool is_comp[N + 1];

bool is_palindrome(int n) {
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < v.size() / 2; i++) {
        if (v[i] != v[v.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 2; i < N; i++) {
        if (!is_comp[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_comp[j] = true;
            }

            if (is_palindrome(i)) {
                p.push_back(i);
            }
        }
    }

    int n;
    cin >> n;
    cout << *lower_bound(p.begin(), p.end(), n);

    return 0;
}