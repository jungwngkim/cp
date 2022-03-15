#include <iostream>
#include <vector>

using namespace std;

int n, x;
vector<pair<int, int>> v;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    v.push_back({ 100000001, 0 });
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        while(v.back().first < x) v.pop_back();
        cout << v.back().second << ' ';
        v.push_back({ x, i });
    }
    
    return 0;
}