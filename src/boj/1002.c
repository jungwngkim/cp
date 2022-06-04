#include <stdio.h>

int calc()
{
    int x1, y1, r1, x2, y2, r2;
    int d_sq, r_diff_sq, r_add_sq;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    if (x1 == x2 && y1 == y2 && r1 == r2)
    {
        return -1;
    }

    d_sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    r_diff_sq = (r1 - r2) * (r1 - r2);
    r_add_sq = (r1 + r2) * (r1 + r2);

    if (d_sq < r_diff_sq || d_sq > r_add_sq)
    {
        return 0;
    }
    else if (d_sq == r_diff_sq || d_sq == r_add_sq)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        printf("%d\n", calc());
    }

    return 0;
}
