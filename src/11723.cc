#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int m;
    cin >> m;

    bool s[21];
    memset(s, false, sizeof(s));

    int x;
    string op;
    while(m--)
    {
        cin >> op;

        if(op == "add")
        {
            cin >> x;
            s[x] = true;
        }
        else if(op == "remove")
        {
            cin >> x;
            s[x] = false;
        }
        else if(op == "check")
        {
            cin >> x;
            cout << s[x] << '\n';
        }
        else if(op == "toggle")
        {
            cin >> x;
            s[x] = !s[x];
        }
        else if(op == "all")
        {
            memset(s, true, sizeof(s));
        }
        else if(op == "empty")
        {
            memset(s, false, sizeof(s));
        }
    }

    return 0;
}