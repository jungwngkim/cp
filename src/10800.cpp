#include <iostream>
#include <vector>

#define N 200001

using namespace std;

struct Ball 
{
    int idx, color;
};

int n;
int tsum, csum[N], ans[N];
vector<Ball> balls[2001];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int c, s;
        cin >> c >> s;
        balls[s].push_back({ i, c });
    }

    for(int s = 1; s <= 2000; s++)
    {
        for(Ball b : balls[s])
        {
            ans[b.idx] = tsum - csum[b.color];
        }

        for(Ball b : balls[s])
        {
            tsum += s;
            csum[b.color] += s;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << '\n';
    }
    
    return 0;
}