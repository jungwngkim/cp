#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long x, y, dist;
        scanf("%ld %ld", &x, &y);
        dist = y - x;
        
        long moved = 1;
        long diff = 0;
        long turn = 1;

        while (moved < dist)
        {
            diff++;

            turn++;
            moved += diff;
            if (dist <= moved)
                break;

            turn++;
            moved += diff;
            if (dist <= moved)
                break;
        }
        
        if (moved > dist)
        {
            turn--;
        }
        
        printf("%ld\n", turn);
    }
    return 0;
}

// 1
// 11
// 111
// 121
// 1121
// 1221
// 11221
// 12221
// 12321
// 112321
// 122321
// 123321
// 1123321
// 1223321
// 1233321
// 1234321

// 0(0) 1(1) 2(2) 4(3) 6(4) 9(5) 12(6) 16(7)
// 1 1 2 2 3 3 4 4
// 2 6 12 20
// k(k+1) < x <= n (k(k+1))
// max distance: t