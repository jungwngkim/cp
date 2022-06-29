#include <stdio.h>

using namespace std;

int s[20][20], n, ans = 0x3f3f3f3f;
bool used[20];

int abs(int a)
{
    return a > 0 ? a : -a;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve(int curr, int cnt)
{
    if(cnt > n / 2) return;

    if (curr == n)
    {
        if (cnt == n / 2)
        {
            int curr_ans = 0;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if(used[i] && used[j]) curr_ans += s[i][j];
                    if(!used[i] && !used[j]) curr_ans -= s[i][j];
                }
            }

            ans = min(ans, abs(curr_ans));
        }

        return;
    }

    used[curr] = true;
    solve(curr + 1, cnt + 1);

    used[curr] = false;
    solve(curr + 1, cnt);
}

int main()
{
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &t), s[i][j] += t, s[j][i] += t;

    solve(0, 0);
    printf("%d", ans);
    return 0;
}