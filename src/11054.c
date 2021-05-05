#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int arr[1010], n, ans = 0, forward_length[1010], backward_length[1010];

    memset(arr, 0, sizeof(arr));

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int max_length = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j] && forward_length[j] > max_length)
            {
                max_length = forward_length[j];
            }
        }
        forward_length[i] = max_length + 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int max_length = 0;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i] > arr[j] && backward_length[j] > max_length)
            {
                max_length = backward_length[j];
            }
        }
        backward_length[i] = max_length + 1;
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, forward_length[i] + backward_length[i]);
    }

    printf("%d", ans - 1);
}