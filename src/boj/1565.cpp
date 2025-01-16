#include <iostream>

using namespace std;

int lcm(int a, int b) {
    return a / gcd(a, b) * b
}

int gcd(int a, int b) {
    return b ? a : gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    

    return 0;
}
