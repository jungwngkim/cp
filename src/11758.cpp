#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int p[3][2], v[2][2];
    for(int i = 0; i < 3; i++) cin >> p[i][0] >> p[i][1];
    for(int i = 0; i < 2; i++) 
    {
        v[i][0] = p[i + 1][0] - p[i][0];
        v[i][1] = p[i + 1][1] - p[i][1];
    }

    int cross = v[0][0] * v[1][1] - v[0][1] * v[1][0];
    cout << (cross == 0 ? 0 : cross < 0 ? -1 : 1);

    return 0;
}