#include <iostream>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;

    long long left = 1, right = N * N, mid, sum, ans;
    while (left <= right)
    {
        mid = (left + right) / 2;

        sum = 0;
        for (long long i = 1; i <= N; i++)
        {
            sum += min(mid / i, N);
        }

        if (sum >= K)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans;

    return 0;
}