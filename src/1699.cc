#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, arr[100001];
    cin >> N;

    for (int i = 0; i <= N; i++)
        arr[i] = i;

    for (int i = 2; i <= (int)floor(sqrt(N)); i++)
    {
        int inc = i * i;
        for (int j = inc; j <= N; j++)
        {
            arr[j] = min(arr[j], arr[j - inc] + 1);
        }
    }

    cout << arr[N];

    return 0;
}