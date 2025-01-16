#include <iostream>
#include <vector>

using namespace std;

int n;
int count[1001];

void print(int a, int c)
{
    for (int i = 0; i < c; i++)
    {
        cout << a << ' ';
    }
    count[a] -= c;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int s[3], sn;
    int a_min = 1000, a_max = 1;

    cin >> n;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        count[a]++;
        a_min = min(a_min, a);
        a_max = max(a_max, a);
    }

    while (true)
    {        
        sn = 0;
        for (int a = a_min; a <= a_max && sn < 3; a++)
        {
            if (count[a])
            {
                s[sn++] = a;
            }
        }

        if (sn == 1)
        {
            print(s[0], count[s[0]]);
            break;
        }
        else if (sn == 2)
        {
            if (s[0] + 1 == s[1])
            {
                swap(s[0], s[1]);
            }
            print(s[0], count[s[0]]);
            print(s[1], count[s[1]]);
            break;
        }
        else
        {
            print(s[0], count[s[0]]);
            a_min = s[1];
            if (s[0] + 1 == s[1])
            {
                print(s[2], 1);
            }
        }
    }

    return 0;
}