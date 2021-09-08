#include <iostream>

using namespace std;

int main()
{
    cout << fixed;
    cout.precision(6);

    double R, PI = 3.14159265358979323846264338;

    cin >> R;
    cout << R * R * PI << '\n';
    cout << (2 * R) * (2 * R) / 2;

    return 0;
}