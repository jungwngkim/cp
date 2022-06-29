#include <iostream>
#include <set>

using namespace std;

int len;
string str;
set<string> st;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> str;
    len = str.length();

    for(int i = 0; i < len; i++) {
        for(int j = 1; j <= len - i; j++) {
            st.insert(str.substr(i, j));
        }
    }

    cout << st.size();
    
    return 0;
}