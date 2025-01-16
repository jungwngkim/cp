#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s;
    while(cin >> n >> s) cout << s / (n + 1) << '\n';

    return 0;
}