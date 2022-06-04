#include <iostream>

using namespace std;

int t, n;
string s;

bool check() {
    int i = 0;
    bool finish = true;
    while(i < n && finish) {
        switch(s[i]) {
            case '0':
                
            case 1:

        }
    }
    
    return;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        cout << (check() ? "YES" : "NO") << '\n';
    }
    
    return 0;
}