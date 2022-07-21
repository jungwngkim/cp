#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n;
    string s, t, lo;
    cin >> s;

    n = s.length();

    if(n == 1) {
        cout << s << ' ' << s;
    }
    else if(n == 2) {
        if(s[0] + 1 == s[1]) {
            cout << s[0] - '0' << ' ' << s[1] - '0';
        }
        else {
            cout << s << ' ' << s;
        }
    }
    else {
        for(int i = 1; i <= 3; i++) {
            lo = s.substr(0, i);
            t = s;
            while(t.length() != 0 && t.find(lo) == 0) {
                t = t.substr(lo.length());
                lo = to_string(stoi(lo) + 1);
            }

            if(t.length() == 0) {
                cout << s.substr(0, i) << ' ' << stoi(lo) - 1;
                break;
            }
        }
    }

    return 0;
}