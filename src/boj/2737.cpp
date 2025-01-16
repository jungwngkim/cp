#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // k, k+1
    // k-1, k, k+1 => k로 나누어지면 됨.
    // k-1, k, k+1, k+2 => a+k/2가 k로 나누어지면 됨

    int t, n, cnt;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt = 0;
        for (int i = 3; n / i - i / 2 >= 0; i += 2)
        {
            if (n % i == 0)
            {
                cnt++;
            }
        }
        for (int i = 2; n / i - i / 2 >= 0; i += 2)
        {
            if ((n + i / 2) % i == 0)
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}