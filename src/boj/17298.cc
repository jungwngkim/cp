#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int *ans = (int *)malloc(sizeof(int) * n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}