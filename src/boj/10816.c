#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int bin_search_front(int *arr, int N, int target_num)
{
    int lo = 0, hi = N - 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(arr[mid] < target_num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int bin_search_back(int *arr, int N, int target_num)
{
    int lo = 0, hi = N - 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(arr[mid] <= target_num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return hi;
}

int main()
{
    int N, M;
    int *arr;
    scanf("%d", &N);
    arr = malloc((N + 1) * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    qsort(arr, N, sizeof(int), (int (*)(const void *, const void *))int_cmp);

    scanf("%d", &M);
    while (M--)
    {
        int target_num;
        scanf("%d", &target_num);
        printf("%d ", bin_search_back(arr, N, target_num) - bin_search_front(arr, N, target_num) + 1);
    }

    free(arr);
}