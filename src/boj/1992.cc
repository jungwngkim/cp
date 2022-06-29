#include <iostream>

using namespace std;

int arr[64][64];

void calc(int y, int x, int w)
{
    int cnt = 0;
    for (int dy = 0; dy < w; dy++)
        for (int dx = 0; dx < w; dx++)
            cnt += arr[y + dy][x + dx];

    if (cnt == 0) // all 0
    {
        cout << 0;
    }
    else if (cnt == w * w) // all 1
    {
        cout << 1;
    }
    else
    {
        cout << '(';
        calc(y, x, w / 2); 
        calc(y, x + w / 2, w / 2);
        calc(y + w / 2, x, w / 2);
        calc(y + w / 2, x + w / 2, w / 2);
        cout << ')';
    }
}

int main()
{
    int N;
    cin >> N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            char t;
            cin >> t;
            arr[y][x] = t - '0';
        }
    }

    calc(0, 0, N);

    return 0;
}