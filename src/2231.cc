#include <iostream>

using namespace std;

int decomp_sum(int n)
{
    int sum = n;
    
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int N, ans = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (decomp_sum(i) == N)
        {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}