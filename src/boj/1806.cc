#include <iostream>

using namespace std;

int N, S, arr[100000];

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int lo = 0, hi = 0, ans = N + 1, sum = 0;
    while (hi <= N)
    {
        if (sum >= S)
        {
            ans = min(ans, hi - lo);
            sum -= arr[lo];
            lo++;
        }
        else
        {
            sum += arr[hi];
            hi++;
        }
    }

    cout << ((ans == N + 1) ? 0 : ans);

    return 0;
}