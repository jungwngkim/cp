#include <stdio.h>

int solve(int n)
{
    int mul = 0, i;
    for (i = 1; mul * 6 + 1 < n; i++)
    {   
        mul += i;
    }
    return i;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d", solve(n));

    return 0;
}