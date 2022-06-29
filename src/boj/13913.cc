#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    int p[100001];

    memset(p, -1, sizeof(p));
    p[n] = -2;
    q.push({n, 0});

    while(!q.empty())
    {
        int x = q.front().first;
        int dist_x = q.front().second;
        q.pop();

        if(x == k)
        {
            cout << dist_x << '\n';
            break;
        }

        if(x - 1 >= 0 && p[x - 1] == -1)
        {
            p[x - 1] = x;
            q.push({x - 1, dist_x + 1});
        }

        if(x + 1 <= 100000 && p[x + 1] == -1)
        {
            p[x + 1] = x;
            q.push({x + 1, dist_x + 1});
        }

        if(x * 2 <= 100000 && p[x * 2] == -1)
        {
            p[x * 2] = x;
            q.push({x * 2, dist_x + 1});
        }
    }

    vector<int> ans;
    int pos = k;
    while(pos != -2)
    {
        ans.push_back(pos);
        pos = p[pos];
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        cout << *it << ' ';
    }

    return 0;
}