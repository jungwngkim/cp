#include <iostream>

using namespace std;

int main()
{
    int N, M;
    bool board[50][50];
    char c;

    cin >> N >> M;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
        {
            cin >> c;
            board[y][x] = c == 'W';
        }

    int ans = 2500;
    for (int i = 0; i < N - 8 + 1; i++)
    {
        for (int j = 0; j < M - 8 + 1; j++)
        {
            int w_start_sum = 0;
            for (int y = 0; y < 8; y++)
                for (int x = 0; x < 8; x++)
                    if (board[y + i][x + j] == ((y + x) % 2 == 0))
                        w_start_sum++;

            ans = min(ans, w_start_sum);

            int b_start_sum = 0;
            for (int y = 0; y < 8; y++)
                for (int x = 0; x < 8; x++)
                    if (board[y + i][x + j] == ((y + x) % 2 == 1))
                        b_start_sum++;

            ans = min(ans, b_start_sum);
        }
    }
    cout << ans;

    return 0;
}