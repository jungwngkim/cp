#include <iostream>

using namespace std;

int N, M, K, A[101][101], B[101][101], C[101][101];

int main()
{
    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> A[y][x];

    cin >> M >> K;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < K; x++)
            cin >> B[y][x];

    for (int y = 0; y < N; y++)
        for (int x = 0; x < K; x++)
            for (int i = 0; i < M; i++)
                C[y][x] += A[y][i] * B[i][x];

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < K; x++)
        {
            cout << C[y][x] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}