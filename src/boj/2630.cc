#include <iostream>

using namespace std;

int arr[128][128], w_cnt, b_cnt;

void calc(int y, int x, int w)
{

    int cnt = 0;
    for (int dy = 0; dy < w; dy++)
        for (int dx = 0; dx < w; dx++)
            cnt += arr[y + dy][x + dx];

    if (cnt == 0)
    {
        w_cnt++;
    }
    else if (cnt == w * w)
    {
        b_cnt++;
    }
    else
    {
        calc(y, x, w / 2);
        calc(y + w / 2, x, w / 2);
        calc(y, x + w / 2, w / 2);
        calc(y + w / 2, x + w / 2, w / 2);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> arr[y][x];

    calc(0, 0, N);

    cout << w_cnt << '\n'
         << b_cnt;

    return 0;
}