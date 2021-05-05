#include <stdio.h>
#include <string.h>

int main()
{
    int arr[10010], N, temp, max = 0;

    scanf("%d", &N);
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        arr[temp]++;

        if(temp > max) {
            max = temp;
        }
    }

    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i);
        }
    }    
}
