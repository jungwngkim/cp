#include <stdio.h>
#include <stdlib.h>

long long get_N(long long *arr, long long K, long long n)
{
    long long ans = 0;
    for (long long i = 0; i < K; i++)
    {
        ans += arr[i] / n;
    }
    return ans;
}

int main()
{
    long long K, *arr, N;
    scanf("%lld %lld", &K, &N);
    arr = (long long *)malloc(K * sizeof(long long));
    for (long long i = 0; i < K; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long max_val = arr[0];
    for (long long i = 1; i < K; i++)
    {
        if (max_val < arr[i])
            max_val = arr[i];
    }

    long long lo = 1, hi = max_val, mid, curr_N;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        curr_N = get_N(arr, K, mid);

        if (curr_N >= N)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    printf("%lld", hi);

    return 0;
}