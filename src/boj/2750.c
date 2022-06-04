#include <stdio.h>

int main()
{
    int n, arr[1000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        } 
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
