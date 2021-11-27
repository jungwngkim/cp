#include <iostream>
#include <cstring>

using namespace std;

int n, w;
pair<int, int> pos[1001];
int memo[1001][1001];

pair<int, int> get_pos(int i, int f)
{
    if(i == 0)
    {
        if(f == 1) return { 1, 1 };
        else return { n, n };
    }
    else return pos[i];
}

int dist(int i, int f, int k)
{
    pair<int, int> pos_i = get_pos(i, f);
    return abs(pos_i.first - pos[k].first) + abs(pos_i.second - pos[k].second);
}

int min_path(int i, int j)
{
    if(i == w || j == w) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    int k = max(i, j) + 1;
    return memo[i][j] = min(min_path(k, j) + dist(i, 1, k), min_path(i, k) + dist(j, 2, k));
}

void print_path(int i, int j)
{
    if(i == w || j == w) return;
    int k = max(i, j) + 1;

    if(memo[k][j] + dist(i, 1, k) < memo[i][k] + dist(j, 2, k))
    {
        cout << 1 << '\n';
        print_path(k, j);
    }
    else 
    {
        cout << 2 << '\n';
        print_path(i, k);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(0);

    cin >> n >> w;
    for(int i = 1; i <= w; i++)
        cin >> pos[i].first >> pos[i].second;
    
    memset(memo, -1, sizeof(memo));

    cout << min_path(0, 0) << '\n';
    print_path(0, 0);

    return 0;
}