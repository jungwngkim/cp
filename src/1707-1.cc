#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    int colors[20001], from, to, v, e;
    bool yes;
    while (t--)
    {
        scanf("%d %d", &v, &e);
        memset(colors, -1, sizeof(colors));
        yes = true;
        for (int i = 0; i < e; i++)
        {
            scanf("%d %d", &from, &to);

            if (colors[from] == -1)
            {
                if (colors[to] == -1)
                {
                    colors[from] = 0;
                    colors[to] = 1;
                }
                else
                {
                    colors[from] = (colors[to] + 1) % 2;
                }
            }
            else
            {
                if (colors[to] == -1)
                {
                    colors[to] = (colors[from] + 1) % 2;
                }
                else
                {
                    if (colors[from] == colors[to])
                    {
                        yes = false;
                        break;
                    }
                }
            }
        }

        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}