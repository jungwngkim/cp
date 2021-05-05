#include <stdio.h>

void move(int from, int to)
{
    printf("%d %d\n", from, to);
}

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
        move(from, to);
    else
    {
        hanoi(n - 1, from, to, by);
        move(from, to);
        hanoi(n - 1, by, from, to);
    }
}

int pow_2(int k) {
    if(k == 1)
        return 2;
    return 2 * pow_2(k-1);
}

int main()
{
    int k;
    scanf("%d", &k);
    printf("%d\n", pow_2(k) - 1);
    hanoi(k, 1, 2, 3);
    return 0;
}
