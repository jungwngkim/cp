#include <stdio.h>
#include <string.h>

long arr[12][105], sum = 0;
int N;

void print_arr()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    memset(arr, 0, sizeof(arr));
    scanf("%d", &N);

    for (int i = 2; i <= 10; i++)
    {
        arr[i][0] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            arr[j][i] = (arr[j - 1][i - 1] + arr[j + 1][i - 1]) % 1000000000;
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        sum += arr[i][N-1];
    }

    printf("%ld\n", sum % 1000000000);
}