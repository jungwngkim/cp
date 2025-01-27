#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string a, b, c;

    cin >> a >> b >> c;

    cout << stoi(a) + stoi(b) - stoi(c) << '\n';
    cout << stoi(a + b) - stoi(c) << '\n';

    return 0;
}
