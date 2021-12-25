#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m; 
    set<string> s;

    cin >> n >> m;
    while(n--)
    {
        string str; 
        cin >> str;
        s.insert(str);
    }

    int cnt = 0;
    while(m--)
    {
        string str; 
        cin >> str;
        cnt += s.count(str);
    }
    cout << cnt;

    return 0;
}