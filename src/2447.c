#include <stdio.h>
#include <string.h>

int arr[2187][2187];

void solve(int x, int y, int num)
{
    if(num == 1) {
        arr[x][y] = 1;
        return;
    }
    int sub = num / 3;
    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++)
        {
            if(i == 1 && j == 1) {
                continue;
            } 
            solve(x + sub * i, y + sub * j, sub);
        }
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    memset(arr, 0, sizeof(arr));
    solve(0, 0, a);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if(arr[i][j] == 0)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
