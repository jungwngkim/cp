#include <iostream>

using namespace std;

int arr[2187][2187], no_num, z_num, o_num;

void calc(int y, int x, int w)
{
    int cnt = 0;
    bool all_zero = true;
    for (int dy = 0; dy < w; dy++)
    {
        for (int dx = 0; dx < w; dx++)
        {
            cnt += arr[y + dy][x + dx];
            all_zero = all_zero && (arr[y + dy][x + dx] == 0);
        }
    }

    if (all_zero && (cnt == 0))
        z_num++;
    else if (cnt == w * w)
        o_num++;
    else if (cnt == -w * w)
        no_num++;
    else
    {
        w /= 3;
        calc(y, x, w);
        calc(y, x + w, w);
        calc(y, x + w * 2, w);
        calc(y + w, x, w);
        calc(y + w, x + w, w);
        calc(y + w, x + w * 2, w);
        calc(y + w * 2, x, w);
        calc(y + w * 2, x + w, w);
        calc(y + w * 2, x + w * 2, w);
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
    cout << no_num << '\n'
         << z_num << '\n'
         << o_num;
    return 0;
}