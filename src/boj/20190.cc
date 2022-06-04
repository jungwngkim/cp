#include <iostream>

using namespace std;

int main()
{
    int arr[300000], a[300000][2];
    int S = 0, N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        a[i][0] = a[i][1] = 0;
        for (int j = 0; j < i; j++) if (arr[i] < arr[j]) a[i][0]++;
        for (int j = i + 1; j < N; j++) if (arr[i] > arr[j]) a[i][1]++;
    }
    for (int i = 0; i < N; i++)
    {
        S += a[i][1];
    }
    for (int i = 0; i < N; i++)
    {
        cout << S - max(a[i][0], a[i][1]) << ' ';
    }
    
    return 0;
}