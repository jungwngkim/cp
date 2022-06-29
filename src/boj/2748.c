#include <stdio.h>
#include <string.h>

long arr[100];

long calc_fib(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <= num; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[num];
}

int main()
{
    int a;
    scanf("%d", &a);
    memset(arr, 0, sizeof(arr));

    printf("%ld", calc_fib(a));
    return 0;
}