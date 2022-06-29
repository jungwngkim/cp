#include <stdio.h>

int fact(int num) {
    if(num == 0) {
        return 1;
    }
    return num * fact(num - 1);
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", fact(a));
    return 0;
}