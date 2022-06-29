#include <iostream>

using namespace std;

int s[2][100000];

int main()
{
    s[0][0] = s[1][0] = 0;
    
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> s[0][i];
        for (int i = 1; i <= N; i++)
            cin >> s[1][i];

        for (int i = 2; i <= N; i++)
        {
            s[0][i] += max(s[1][i-1], max(s[0][i-2], s[1][i-2]));
            s[1][i] += max(s[0][i-1], max(s[0][i-2], s[1][i-2]));
        }

        cout << max(s[0][N], s[1][N]) << '\n';
    }

    return 0;
}