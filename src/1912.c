#include <stdio.h>
#include <string.h>

#define MIN -1987654321

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int arr[100010], sum[100010], n, ans;

    scanf("%d", &n);
    sum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    ans = MIN;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = max(sum[i-1] + arr[i], arr[i]);
        ans = max(sum[i], ans);
    }

    printf("%d", ans);
}