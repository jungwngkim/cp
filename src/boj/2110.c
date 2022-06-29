#include <stdio.h>
#include <stdlib.h>

int cmp(const int *a, const int *b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main()
{
    int N, C, *arr;
    scanf("%d %d", &N, &C);
    arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), (int (*)(const void *, const void *))cmp);

    int lo = 1, hi = arr[N - 1] - arr[0], mid, c, i, ans = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        c = 1;
        i = 0;
        for (int j = i + 1; j < N; j++)
        {
            if ((arr[j] - arr[i]) >= mid)
            {
                c++;
                i = j;
            }
        }

        if (c >= C)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    printf("%d", hi);

    return 0;
}