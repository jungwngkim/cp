#include <iostream>

using namespace std;

int main()
{
    int a, sum = 0;
    for (int i = 0; i < 5; i++)
        cin >> a, a = a < 40 ? 40 : a, sum += a / 5;
    cout << sum;
    return 0;
}