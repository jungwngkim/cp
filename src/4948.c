#include <stdio.h>
#include <string.h>

int main()
{
    int b, arr[250000];

    memset(arr, 0, sizeof(arr));

    arr[1] = 1;

    while (scanf("%d", &b) && b != 0)
    {
        for (int i = 2; i * i <= 2 * b; i++)
        {
            if (arr[i] == 1)
            {
                continue;
            }
            for (int j = i + i; j <= 2 * b; j += i)
            {
                arr[j] = 1;
            }
        }

        int count = 0;
        for (int i = b + 1; i <= 2 * b; i++)
        {
            if (arr[i] == 0)
                count++;
        }
        printf("%d\n", count);
    }

    return 0;
}