#include <iostream>

using namespace std;

bool is_666(int num)
{
    int six_streak = 0;
    while (num != 0)
    {
        if (num % 10 == 6)
            six_streak++;
        else
            six_streak = 0;

        if (six_streak == 3)
            return true;

        num /= 10;
    }

    return false;
}

int main()
{
    int N;
    cin >> N;

    int n = 666, i = 0;
    while (i < N)
    {
        if (is_666(n)) i++;
        n++;
    }

    cout << n - 1 << '\n';

    return 0;
}