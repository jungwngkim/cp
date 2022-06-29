#include <iostream>

using namespace std;

int h, w, r, c, ans;
int dx[] = { 0, -1, 1, 0 }, dy[] = { -1, 0, 0, 1 };
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> h >> w >> r >> c;

    for(int i = 0; i < 4; i++) {
        ans += (1 <= r + dx[i] && r + dx[i] <= h && 1 <= c + dy[i] && c + dy[i] <= w);
    }

    cout << ans;
    
    return 0;
}