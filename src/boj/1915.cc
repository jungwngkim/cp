#include <iostream>

using namespace std;

int main()
{
    int N, M, arr[1000][1000];
    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            char c;
            cin >> c;
            arr[y][x] = c - '0';
        }
    }

    for (int i = 1; i <= min(N, M); i++)
    {
        for (int y = 0; y < N - i; y++)
        {
            for (int x = 0; x < M - i; x++)
            {
                if (arr[y][x] == i && arr[y + 1][x] == i && arr[y][x + 1] == i && arr[y + 1][x + 1] == i)
                {
                    arr[y][x] = i + 1;
                }
            }
        }
    }

    // for (int y = 0; y < N; y++)
    // {
    //     for (int x = 0; x < M; x++)
    //     {
    //         cout << arr[y][x];
    //     }
    //     cout << '\n';
    // }

    int max_length = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            max_length = max(max_length, arr[y][x]);
        }
    }

    cout << max_length * max_length;

    return 0;
}