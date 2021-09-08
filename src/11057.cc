#include <iostream>

using namespace std;

int main()
{
    int N, arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cin >> N;

    while (N--)
    {
        for (int i = 8; i >= 0; i--)
        {
            arr[i] += arr[i + 1];
            arr[i] %= 10007;
        }
    }

    cout << arr[0];

    return 0;
}