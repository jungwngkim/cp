#include <iostream>

using namespace std;

int **matmul(int **A, int **B, int N)
{
    int **res = new int *[N];
    for (int y = 0; y < N; y++)
    {
        res[y] = new int[N];
        for (int x = 0; x < N; x++)
        {
            res[y][x] = 0;
            for (int i = 0; i < N; i++)
                res[y][x] += (A[y][i] * B[i][x]) % 1000;
        }
    }
    return res;
}

int **matpow(int **A, int N, long B)
{
    int **res = new int *[N];
    for (int y = 0; y < N; y++)
    {
        res[y] = new int[N];
        for (int x = 0; x < N; x++)
            res[y][x] = y == x ? 1 : 0;
    }

    while (B > 0)
    {
        if (B & 1)
            res = matmul(res, A, N);

        A = matmul(A, A, N);
        B >>= 1;
    }

    return res;
}

int main()
{
    int N;
    long B;
    cin >> N >> B;

    int **A = new int *[N];
    for (int y = 0; y < N; y++)
    {
        A[y] = new int[N];
        for (int x = 0; x < N; x++)
            cin >> A[y][x];
    }

    int **res = matpow(A, N, B);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << res[y][x] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}