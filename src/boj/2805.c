#include <stdio.h>
#include <stdlib.h>

long long get_len(int *arr, int N, int base_len)
{
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        int inc = arr[i] - base_len;
        if (inc > 0)
            ans += inc;
    }
    return ans;
}

int main()
{
    int N, M, *arr;
    scanf("%d %d", &N, &M);
    arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max_len = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > max_len)
            max_len = arr[i];
    }

    int lo = 1, hi = max_len, mid;
    long long curr_len;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        curr_len = get_len(arr, N, mid);
        if (curr_len >= M)
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