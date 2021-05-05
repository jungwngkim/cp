#include <stdio.h>

void solve(int n)
{
    int sum = 1, i, top, bot;
    for (i = 1; sum <= n; i++)
    {
        sum += i;
    }
    if (i % 2 == 1)
    {
        bot = sum - n;
        top = i - bot;
    }
    else
    {
        top = sum - n;
        bot = i - top;
    }
    printf("%d/%d", top, bot);
}

int main()
{
    int n;

    scanf("%d", &n);
    solve(n);
    
    return 0;
}