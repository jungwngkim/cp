#include <stdio.h>

int fib(int num) {
    if(num == 0) {
        return 0;
    }
    if(num == 1 || num == 2) {
        return 1;
    }
    return fib(num - 1) + fib(num - 2);
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", fib(a));
    return 0;
}