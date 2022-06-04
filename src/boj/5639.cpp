#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

void post(int left, int right)
{
    if(right <= left) return;
    auto it = lower_bound(v.begin() + left + 1, v.begin() + right, v[left]);
    post(left + 1, it - v.begin());
    post(it - v.begin(), right);
    cout << v[left] << '\n';
}


int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    while(cin >> t) v.push_back(t);
    post(0, v.size());
    return 0;
}