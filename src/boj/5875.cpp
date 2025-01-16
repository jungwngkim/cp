#include <iostream>

using namespace std;

int solve() {
    string str;
    cin >> str;

    int arr[100000], n = str.length();
    for (int i = 0; i < n; i++) {
        arr[i] = str[i] == '(' ? 1 : -1;
    }

    int open_count = 0, close_count = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            open_count++;
        }
        else {
            close_count++;
        }

        s += arr[i];

        if (s == -1) return close_count;
        if (s == 1) open_count = 0;
    }

    return open_count;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << solve();
    return 0;
}
