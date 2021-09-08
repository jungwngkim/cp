#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int arr[1010], n, ans = 0, length[1010];

    memset(arr, 0, sizeof(arr));

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        length[i]++;
    }

    for (int i = 0; i < n; i++)
    {
        int max_length = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j] && length[j] > max_length)
            {
                max_length = length[j];
            }
        }
        length[i] = max_length + 1;
        ans = max(ans, length[i]);
    }

    printf("%d", ans);
}