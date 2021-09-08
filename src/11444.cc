#include <iostream>

#define DIV 1000000007LL

using namespace std;

int main()
{
    long long P[2][2] = {{0, 1}, {1, 1}}, res[2][2] = {{1, 0}, {0, 1}};
    long long n;
    cin >> n;

    while (n > 0)
    {
        if (n & 1)
        {
            // res = res * P
            long long temp[2][2] = {{0, 0}, {0, 0}};
            for (int y = 0; y < 2; y++)
                for (int x = 0; x < 2; x++)
                    for (int i = 0; i < 2; i++)
                        temp[y][x] += res[y][i] * P[i][x] % DIV;
            for (int y = 0; y < 2; y++)
                for (int x = 0; x < 2; x++)
                    res[y][x] = temp[y][x] % DIV;
        }
        // P = P * P
        long long temp[2][2] = {{0, 0}, {0, 0}};
        for (int y = 0; y < 2; y++)
            for (int x = 0; x < 2; x++)
                for (int i = 0; i < 2; i++)
                    temp[y][x] += P[y][i] * P[i][x] % DIV;
        for (int y = 0; y < 2; y++)
            for (int x = 0; x < 2; x++)
                P[y][x] = temp[y][x] % DIV;

        n >>= 1;
    }

    cout << res[1][0];
    return 0;
}