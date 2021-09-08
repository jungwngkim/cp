#include <iostream>
#include <cstring>

using namespace std;

int memo[21][21][21];
bool found[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }

    if (!found[a][b][c])
    {
        found[a][b][c] = true;
        if (a < b && b < c)
            memo[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else
            memo[a][b][c] = w(a - 1, b, c) +
                            w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return memo[a][b][c];
}

int main()
{
    memset(found, false, sizeof(found));

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}
