#include <iostream>
#include <algorithm>

using namespace std;

int N, X, arr[100000];

int Solve()
{
    int lo = 0, hi = N - 1, cnt = 0;
    while (lo < hi)
    {
        if (arr[lo] + arr[hi] < X)
        {
            lo++;
        }
        else if (arr[lo] + arr[hi] > X)
        {
            hi--;
        }
        
        if(arr[lo] + arr[hi] == X)
        {
            cnt++;
            lo++;
            hi--;
        }
    }
    return cnt;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> X;

    sort(arr, arr + N);

    cout << Solve();

    return 0;
}