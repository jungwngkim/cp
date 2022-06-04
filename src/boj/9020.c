#include <stdio.h>
#include <string.h>

int main()
{
    int T, arr[10000];

    scanf("%d", &T);
    memset(arr, 0, sizeof(arr));

    while (T--)
    {
        int num, diff, lo, hi, mid;
        scanf("%d", &num);

        diff = 0;
        mid = num / 2;
        while (1)
        {
            lo = mid - diff, hi = mid + diff;

            for(int i=2; i*i <= hi; i++) {
                if(arr[i] == 1) {
                    continue;
                }
                for (int j = i+i; j <= hi; j+=i)
                {
                    arr[j] = 1;
                }
            }

            if (arr[lo] == 0 && arr[hi] == 0)
            {
                printf("%d %d\n", lo, hi);
                break;
            }
            
            diff++;
        }
    }
    

    return 0;
}