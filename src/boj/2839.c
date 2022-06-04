#include <stdio.h>

int solve(int n)
{
    switch (n % 5)
    {
    case 0:
        return n / 5;
        break;
    case 1:
        if (n - 5 < 0)
        {
            return -1;
        }
        return (n / 5) + 1;
        break;
    case 2:
        if (n - 10 < 0)
        {
            return -1;
        }
        return (n / 5) + 2;
        break;
    case 3:
        return (n / 5) + 1;
        break;
    case 4:
        if (n - 5 < 0)
        {
            return -1;
        }
        return (n / 5) + 2;
        break;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", solve(n));

    return 0;
}