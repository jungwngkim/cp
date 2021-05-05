#include <stdio.h>

int main()
{
    int T, count = 0;
    
    scanf("%d", &T);

    while (T--)
    {
        int num, prime_count = 0;
        scanf("%d", &num);

        if(num == 1) {
            continue;
        }

        for (int i = 2; i * i <= num; i++)
        {
            if(num % i == 0) {
                prime_count++;
            }
        }

        if (prime_count == 0)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}