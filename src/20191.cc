#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),  

    vector<int> v['a' + 26];
    string S, T;

    cin >> S >> T;
    // 모든 글자의 위치를 저장한다.
    for (int i = 0; i < T.length(); i++)
    {
        v[T[i]].push_back(i);
    }

    // S에 있는 글자가 T에 없으면
    // 줄임말을 만들 수 없기 때문에
    // -1을 출력하고 리턴한다.
    for (auto s : S)
    {
        if (v[s].empty())
        {
            cout << -1;
            return 0;
        }
    }

    int count = 1, pos = -1;
    for (auto s : S)
    {
        auto it = lower_bound(v[s].begin(), v[s].end(), pos + 1);
        if (it == v[s].end())
        {
            count++;
            it = v[s].begin();
        }
        pos = *it;
    }

    cout << count;

    return 0;
}
