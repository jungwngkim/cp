#include <stdio.h>

int bin_pow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % 10;
        a = a * a % 10;
        b >>= 1;
    }
    return ans != 0 ? ans : 10;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", bin_pow(a, b));
    }
    return 0;
}