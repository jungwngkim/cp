#include <iostream>
#include <cstring>

using namespace std;

void LCS(string & s1, string & s2)
{
    int N = s1.length(), M = s2.length();
    int L[N + 1][M + 1];
    pair<int, int> P[N + 1][M + 1];

    memset(L, 0, sizeof(L));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(s1[i] == s2[j])
            {
                L[i + 1][j + 1] = L[i][j] + 1;
                P[i + 1][j + 1] = { i, j };
            }
            else 
            {
                if(L[i][j + 1] > L[i + 1][j])
                {
                    L[i + 1][j + 1] = L[i][j + 1];
                    P[i + 1][j + 1] = { i, j + 1 };
                }
                else
                {
                    L[i + 1][j + 1] = L[i + 1][j];
                    P[i + 1][j + 1] = { i + 1, j };
                }
            }
        }
    }

    cout << L[N][M] << '\n';
    int i = N, j = M;
    string ans = "";
    while(i != 0 && j != 0)
    {
        int pi = P[i][j].first, pj = P[i][j].second;
        if(L[i][j] > L[pi][pj]) 
            ans = s1[i - 1] + ans;
        i = pi, j = pj;
    }
    cout << ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    LCS(s1, s2);
    return 0;
}