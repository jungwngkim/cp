#include <iostream>

using namespace std;

int N, M, arr[100], ans = 0;
bool used[100];

void find_blackjack(int sum, int curr)
{
    if (sum > M)
    {
        return;
    }

    if (curr == 3)
    {
        if (sum <= M && sum > ans)
        {
            ans = sum;
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            find_blackjack(sum + arr[i], curr + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        used[i] = false;
    }

    find_blackjack(0, 0);
    cout << ans;

    return 0;
}