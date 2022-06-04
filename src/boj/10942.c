#include <stdio.h>

int main()
{
    static int N, arr[2001], is_palin[2001][2001], M, S, E;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++)
        is_palin[i][i] = 1;

    for (int i = 0; i < N - 1; i++)
        if (arr[i] == arr[i + 1])
            is_palin[i][i + 1] = 1;

    for (int i = 2; i < N; i++)
        for (int j = 0; j < N - i; j++)
            is_palin[j][j + i] = (arr[j] == arr[j + i]) ? is_palin[j + 1][j + i - 1] : 0;

    scanf("%d", &M);
    while (M--)
    {
        scanf("%d %d", &S, &E);
        printf("%d\n", is_palin[S-1][E-1]);
    }

    return 0;
}