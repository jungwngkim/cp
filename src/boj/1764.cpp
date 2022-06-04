#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
string str;
set<string> s;
vector<string> v;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;
    while(n--) {
        cin >> str;
        s.insert(str);
    }

    while(m--) {
        cin >> str;
        if(s.count(str)) {
            v.push_back(str);
        }
    }
    
    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}