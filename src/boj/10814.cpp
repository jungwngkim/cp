#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    pair<int, int> age_idx[100000];
    string name[100000];

    for(int i = 0; i < n; i++)
    {
        cin >> age_idx[i].first >> name[i];
        age_idx[i].second = i;
    }

    sort(age_idx, age_idx + n);

    for(int i = 0; i < n; i++) cout << age_idx[i].first << ' ' << name[age_idx[i].second] << '\n';

    return 0;
}