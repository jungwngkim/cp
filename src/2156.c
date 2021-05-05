#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int arr[10010], n, ans = 0, sum[10010];

    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));

    scanf("%d", &n);

    for (int i = 3; i < n + 3; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 3; i < n + 3; i++)
    {
        sum[i] = max(sum[i - 1], max(sum[i - 2] + arr[i], sum[i - 3] + arr[i] + arr[i - 1]));
        ans = max(ans, sum[i]);
    }

    printf("%d", ans);
}