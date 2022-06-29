#include <stdio.h>
#include <string.h>

int arr[500][500];
int a;

void input_arr()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_arr()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

void calc() {
    for(int i=a-1; i > 0; i--) {
        for (int j = a-2; j >=0; j--)
        {
            arr[i-1][j] += arr[i][j] > arr[i][j + 1] ? arr[i][j] : arr[i][j + 1];
        }
    }
}

int main()
{
    scanf("%d", &a);
    memset(arr, 0, sizeof(arr));

    input_arr();
    // print_arr();

    calc();
    // print_arr();

    printf("%d", arr[0][0]);
    return 0;
}